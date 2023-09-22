from django.contrib.auth.models import AbstractUser
from django.db import models


# Create your models here.

class modelBase(models.Model):
    name = models.CharField(max_length=45,unique=True)
    
    ON = 1
    OFF = 0
    CHOICES = (
        (ON, 'Available'),
        (OFF, 'Unavailable'),
    )

    isAvailable = models.CharField(
        max_length=2,
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
    pass

class User(AbstractUser):
    id = models.AutoField(primary_key=True)
    username = models.CharField(max_length=45,unique=True)
    email = models.CharField(max_length=45,unique=True)
    password = models.CharField(max_length=200)
    isAvailable = models.SmallIntegerField(default=1)

    userType = models.ForeignKey(
        UserType,
        related_name='users',
        on_delete=models.CASCADE,
        blank=True,
        null=True,
        #default=1,
    )

    #USERNAME_FIELD = 'email'
    #REQUIRED_FIELDS = []

#####################################################
####   NOTA:
####   Comentar que es probable que sea necesario 
####   crear una APP independiente que controle 
####   el laboratorio virtual
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
####   NOTA:
####   Los siguientes se pueden ver como extensión
####   del modelo User, ya que un prof, alumno, 
####   es User
# 
# 
#            PENDIENTE MEJORAR ESTA ZONA
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




#####################################################
#            PENDIENTE MEJORAR ESTA ZONA
#    Probablemente se necesite una app que
#    se encargue de manejar cursos. 
#       AÚN POR DEFINIR
#####################################################
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
