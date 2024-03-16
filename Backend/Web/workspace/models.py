from django.db import models

from users.models import User

# Create your models here.
class modelBase(models.Model):  
    name = models.CharField(max_length=450,unique=True)
    extra_content = models.CharField(max_length=4096,unique=True)
    
    ON = 1
    OFF = 0
    CHOICES = (
        (ON, 'Available'),
        (OFF, 'Unavailable'),
    )

    isAvailable = models.IntegerField(
        choices=CHOICES,
        default=OFF,
    )

    class Meta:
        abstract = True

class ComponentList(modelBase):
    pass

class Component(modelBase):
    model = models.CharField(max_length=100)
    
    intrnl_id = models.CharField(max_length=128,default='')
    intrnl_type = models.CharField(max_length=32,default='')
    intrnl_url = models.CharField(max_length=256,default='')
    intrnl_alt = models.CharField(max_length=64,default='')
    inrtnl_x = models.IntegerField(default=128)
    inrtnl_y = models.IntegerField(default=128)
    
    intrnl_pins = models.CharField(max_length=8192,default='')
    
    description = models.CharField(max_length=4096)
    elements = models.ForeignKey(
        ComponentList,
        related_name='componentsinlist',
        on_delete=models.CASCADE,
        default=None
    )

class ComponentType(modelBase):
    component = models.ForeignKey(
        Component,
        related_name='componentsoftype',
        on_delete=models.CASCADE,
        default=None
        )

class MainBoard(modelBase):
    id = models.AutoField(primary_key=True)
    components = models.ForeignKey(
        ComponentList,
        related_name='componentslist',
        on_delete=models.CASCADE
    )
            
    BUSY = 0
    READY = 1
    TESTING = 2
    boardStatus = (
        (BUSY, 'BUSY'),
        (READY, 'READY'),
        (TESTING, 'TESTING')
    )
    
    inputs = models.CharField(max_length=512)
    outputs= models.CharField(max_length=512)

    boardStatus = models.IntegerField(
        choices=boardStatus,
        default=TESTING,
    )

class Contratos(modelBase):
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

class TransaccionesAuditor(modelBase):
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
