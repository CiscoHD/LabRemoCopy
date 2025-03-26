from django.contrib.auth.models import AbstractUser, Group, Permission
from django.db import models

from django.core.exceptions import ValidationError

from datetime import datetime
from datetime import date

from .constants.user_types import UserTypeConfig


# Create your models here.

class modelBase(models.Model):
    name = models.CharField(max_length=99,unique=True)
    
    ON = 1
    OFF = 0
    CHOICES = (
        (ON, 'Available'),
        (OFF, 'Unavailable'),
    )

    isAvailable = models.IntegerField(
        # max_length=2,
        choices=CHOICES,
        default=OFF,
    )

    class Meta:
        abstract = True

class Country(modelBase):
    cKey = models.CharField(max_length=3,unique=True)
    
class Universities(modelBase):
    country = models.ForeignKey(
        Country,
        related_name='universities',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    siglas = models.CharField(max_length=20, blank=True, null=True)
    
    class Meta:
        verbose_name = 'University'
        verbose_name_plural = 'Universities'
        ordering = ['name']

    def clean(self):
        # Ignorar validación si siglas está vacío o es None
        if self.siglas=='':
            return

        if Universities.objects.filter(siglas__iexact=self.siglas).exclude(id=self.id).exists():
            raise ValidationError({'siglas': 'Estas siglas ya existen'})

class Schools(modelBase):
    university = models.ForeignKey(
        Universities,
        related_name='universities',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
        )

class Careers(modelBase):
    name = models.CharField(max_length=200)
    year = models.CharField(max_length=45)
    schools = models.ForeignKey(
        Schools,
        related_name='schools',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )

class Subject(modelBase):
    name = models.CharField(max_length=200)
    credits = models.CharField(max_length=45)
    semesterNumber = models.CharField(max_length=45)
    career = models.ForeignKey(
        Careers,
        related_name='careers',
        on_delete=models.CASCADE,
        #blank=True,
        null=True,
        default=1,
    )
    #created = DateType

class Activity(modelBase):
    name = models.CharField(max_length=200)
    credits = models.CharField(max_length=45)
    #semesterNumber = models.CharField(max_length=45)
    subject = models.ForeignKey(
        Subject,
        related_name='activity_subject',
        on_delete=models.CASCADE,
        #blank=True,
        null=True,
        default=1,
    )
    SerializedSet = models.CharField(max_length=4000,
                                     null=True,)
    #created = DateType

class UserType(modelBase):
    """Modelo para tipos de usuario"""
    # Constantes
    STUDENT = UserTypeConfig.STUDENT
    TEACHER = UserTypeConfig.TEACHER
    STAFF = UserTypeConfig.STAFF
    ADMIN = UserTypeConfig.ADMIN
    
    TYPE_CHOICES = UserTypeConfig.TYPE_CHOICES
    GROUP_NAMES = UserTypeConfig.GROUP_NAMES
    
    code = models.CharField(
        max_length=3,
        choices=TYPE_CHOICES,
        unique=True,
        verbose_name='Código'
    )
    
    group = models.OneToOneField(
        Group,
        on_delete=models.SET_NULL,
        null=True,
        blank=True,
        related_name='user_type'
    )

    def save(self, *args, **kwargs):
        """Override save para crear/actualizar grupo automáticamente"""
        creating = self._state.adding  # Verifica si es creación nueva
        
        super().save(*args, **kwargs)  # Guarda primero el UserType
        
        if creating or not self.group:
            group_name = UserTypeConfig.GROUP_NAMES.get(self.code)
            if group_name:
                # Crea o obtiene el grupo
                group, created = Group.objects.get_or_create(name=group_name)
                self.group = group
                self.save()  # Guarda nuevamente con el grupo asignad
    
    def __str__(self):
        return UserTypeConfig.get_display_name(self.code)

class User(AbstractUser):
    id = models.AutoField(primary_key=True)
    username = models.CharField(max_length=45, unique=True)
    email = models.CharField(max_length=45, unique=True)
    password = models.CharField(max_length=200)
    
    # Estado disponible (usando constantes para evitar magic numbers)
    class Availability:
        ON = 1
        OFF = 0
        CHOICES = (
            (ON, 'Available'),
            (OFF, 'Unavailable'),
        )
    
    isAvailable = models.IntegerField(
        choices=Availability.CHOICES,
        default=Availability.OFF,
    )
    
    user_type = models.ForeignKey(
        'UserType',
        related_name='users',
        on_delete=models.SET_NULL,
        blank=True,
        null=True
    )

    # Métodos base
    @property
    def getId(self):
        return self.id

    # Propiedades de tipo (usando UserTypeConfig como fuente de verdad)
    @property
    def is_student(self):
        return self._check_type(UserTypeConfig.STUDENT)

    @property
    def is_teacher(self):
        return self._check_type(UserTypeConfig.TEACHER)

    @property
    def is_staff_member(self):
        return self._check_type(UserTypeConfig.STAFF)

    @property
    def is_admin_user(self):
        return self._check_type(UserTypeConfig.ADMIN) or self.is_superuser

    # Métodos de apoyo
    def _check_type(self, target_code):
        """Verifica tanto user_type como grupos"""
        type_matches = self.user_type and self.user_type.code == target_code
        group_matches = self._check_group(target_code)
        return type_matches or group_matches

    def _check_group(self, target_code):
        """Verifica pertenencia a grupo sin hardcodear strings"""
        group_name = UserTypeConfig.GROUP_NAMES.get(target_code)
        return group_name and self.groups.filter(name=group_name).exists()

    def sync_groups(self):
        """Sincroniza grupos con el user_type actual"""
        if self.user_type:
            group_name = UserTypeConfig.GROUP_NAMES.get(self.user_type.code)
            if group_name:
                group, _ = Group.objects.get_or_create(name=group_name)
                self.groups.set([group])  # Reemplaza cualquier grupo existente
                if not self.user_type.group:
                    self.user_type.group = group
                    self.user_type.save()

    def get_user_type_display(self):
        """Versión mejorada que usa UserTypeConfig"""
        if self.user_type:
            return UserTypeConfig.get_display_name(self.user_type.code)
        return "Sin tipo asignado"

    # Metadata adicional
    class Meta:
        verbose_name = 'Usuario'
        verbose_name_plural = 'Usuarios'
        permissions = [
            ('can_manage_students', 'Puede gestionar estudiantes'),
            ('can_manage_teachers', 'Puede gestionar profesores'),
        ]

    def __str__(self):
        return f"{self.username} ({self.get_user_type_display()})"

#####################################################
####   NOTA:                                       **
####   Comentar que es probable que sea necesario  **
####   crear una APP independiente que controle    **
####   el laboratorio virtual                      **
#####################################################
class AuthorLabSessions(modelBase):
    name = None
    isAvailable = models.SmallIntegerField()
    user = models.ForeignKey(
        User,
        related_name='authorlabsessions',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    
class LabSessions(modelBase):
    serializedSet = models.TextField()
    subject = models.ForeignKey(
        Subject,
        related_name='subject',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    authorLabSession = models.ForeignKey(
        AuthorLabSessions,
        related_name='authorlabsessions',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    #created = DateType

#####################################################
####   NOTA:                                       **
####   Los siguientes se pueden ver como extensión **
####   del modelo User, ya que un prof, alumno,    **
####   es User                                     **
#                                                  **
#                                                  **
#            PENDIENTE MEJORAR ESTA ZONA           **
#####################################################

class Student(modelBase):
    name = None
    career = models.ForeignKey(
        Careers,
        related_name='student_careers',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )

class Professor(modelBase):
    user = models.ForeignKey(
        User,
        related_name='user',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )

######################################################


######################################################
#            PENDIENTE MEJORAR ESTA ZONA            **
#    Probablemente se necesite una app que          **
#    se encargue de manejar cursos.                 **
#       AÚN POR DEFINIR                             **
######################################################
class Course(modelBase):
    name = None
    semesterId = models.CharField(max_length=45)
    groupId = models.IntegerField()
    professor = models.ForeignKey(
        Professor,
        related_name='professor',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    subject = models.ForeignKey(
        Subject,
        related_name='course_subject',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    
    #created = Datetype

class Roster(modelBase):
    name = None
    students = models.ForeignKey(
        Student,
        related_name='students',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    course = models.ForeignKey(
        Course,
        related_name='courses',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    
class StudentLabSession(modelBase):
    name = None
    serializedSet = models.TextField()
    sharedLink = models.CharField(max_length=45)
    roster = models.ForeignKey(
        Roster,
        related_name='roster',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )
    labSession = models.ForeignKey(
        LabSessions,
        related_name='labsessions',
        on_delete=models.CASCADE,
        #blank=True,
        #null=True,
        default=1,
    )

# class DuinoFile(models.Model):
#     #date_time = date.today()
#     date_time = datetime.now()
#     file = models.FileField(upload_to='user_{0}/{1}'.format(1,date_time.strftime("%m-%d-%Y-%H:%M:%S/")), max_length=100)

class UploadedFile(models.Model):

    uploaded_on = models.DateTimeField(auto_now_add=True)

    path_archivo = models.CharField(max_length=1024)
    
    id_estudiante = models.ForeignKey(
        User,
        related_name='archivos_estudiante',
        on_delete = models.CASCADE,
        default=1,
    )
    id_practica = models.ForeignKey(
        Activity,
        related_name='archivos_practica',
        on_delete=models.CASCADE,
        default=1,
    )
    id_session = models.ForeignKey(
        LabSessions,
        related_name='archivos_session',
        on_delete=models.CASCADE,
        default=1
    )
    

    def get_path(instance,filename):
        return 'u{0}a{1}s{2}.{3}'.format(instance.id_estudiante.id,
                                     instance.id_practica.id,
                                     instance.id_session.id,
                                     filename.split('.')[-1])
    
    file = models.FileField(upload_to=get_path)


    
    # def save(self,*args,**kwargs):
    #     # self.path_archivo =self.get_path()
    #     super(UploadedFile,self).save(*args,**kwargs)
    
    def __str__(self):
        return str(self.uploaded_on.date())