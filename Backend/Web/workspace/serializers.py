from rest_framework import serializers, generics
from .models import (
                    # Component, ComponentList, MainBoard,
                     Contratos,TransaccionesAuditor, Componente, TipoComponente
                     )
        

class TipoComponenteSerializer(serializers.ModelSerializer):
    class Meta:
        model = TipoComponente
        fields = ['id', 'nombre', 'descripcion']

class ComponenteSerializer(serializers.ModelSerializer):
    tipo = TipoComponenteSerializer(read_only=True)
    tipo_id = serializers.PrimaryKeyRelatedField(
        queryset=TipoComponente.objects.all(),
        source='tipo',
        write_only=True
    )
    
    class Meta:
        model = Componente
        fields = [
            'id',
            'nombre',
            'descripcion',
            'tipo',
            'tipo_id',
            'especificaciones',
            'estado',
            'fecha_creacion',
            'fecha_actualizacion'
        ]
        read_only_fields = ['fecha_creacion', 'fecha_actualizacion']
    
    def validate_especificaciones(self, value):
        if not isinstance(value, (dict, list)):
            raise serializers.ValidationError("Las especificaciones deben ser un objeto JSON válido")
        return value

def GenericGeneratorSerializer(modell,cerealizer,fieldss='__all__'):
    class GenericSerializer(cerealizer):
        class Meta:
            model = modell
            fields = fieldss
    return GenericSerializer


class ContratosSerializer(serializers.ModelSerializer):
    class Meta:
        model = Contratos
        fields = '__all__'

class TransaccionesSerializer(serializers.ModelSerializer):
    class Meta:
        model = TransaccionesAuditor
        fields = '__all__'    