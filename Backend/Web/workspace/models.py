from django.db import models

from django.db.models import JSONField  # Si usas PostgreSQL

from users.models import User

# Create your models here.
class TipoComponente(models.Model):
    nombre = models.CharField(max_length=100, unique=True)
    descripcion = models.CharField(max_length=500, blank=True, null=True)

    def __str__(self):
        return self.nombre

class ComponenteBase(models.Model):
    nombre = models.CharField(max_length=450, unique=True)
    descripcion = models.CharField(max_length=4096, blank=True, null=True)
    
    # Estado del componente
    DISPONIBLE = 1
    NO_DISPONIBLE = 0
    ESTADO_CHOICES = (
        (DISPONIBLE, 'Disponible'),
        (NO_DISPONIBLE, 'No Disponible'),
    )
    estado = models.IntegerField(choices=ESTADO_CHOICES, default=DISPONIBLE)

    class Meta:
        abstract = True

class Componente(ComponenteBase):
    tipo = models.ForeignKey(TipoComponente, on_delete=models.PROTECT, related_name='componentes')
    especificaciones = JSONField()
    fecha_creacion = models.DateTimeField(auto_now_add=True)
    fecha_actualizacion = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f"{self.nombre} ({self.tipo.nombre})"

class Contratos(models.Model):
    #id_contrato = models.AutoField(primary_key=True)
    nombre_contrato = models.CharField(max_length=128,unique=True)
    tipo_contrato = models.CharField(max_length=128,unique=True)
    contrato = models.CharField(max_length=128,unique=True)
    consideraciones = models.CharField(max_length=4096)

# class Contratos2(modelBase):
#     #id_contrato = models.AutoField(primary_key=True)
#     nombre_contrato = models.CharField(max_length=128,unique=True)
#     tipo_contrato = models.CharField(max_length=128,unique=True)
#     contrato = models.CharField(max_length=128,unique=True)
#     consideraciones = models.CharField(max_length=4096)

class TransaccionesAuditor(models.Model):
    #id_node = models.AutoField(primary_key=True)
    name_node = models.CharField(max_length=128,unique=True)
    type_transaction = models.CharField(max_length=128)
    date_process = models.DateField(auto_now=True)
    id_user = models.ForeignKey(
        User,
        related_name='contratos_user',
        on_delete=models.CASCADE,
    )

    log_process = models.CharField(max_length=1024)
