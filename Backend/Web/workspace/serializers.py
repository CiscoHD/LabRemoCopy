from rest_framework import serializers, generics
from .models import (Component, ComponentList, MainBoard)
        
class ComponentSerializer(serializers.ModelSerializer):
    class Meta:
        model = Component
        fields = '__all__'
        
class ComponentListSerializer(serializers.ModelSerializer):
    class Meta:
        model = ComponentList
        fields = '__all__'
        
class MainBoardSerializer(serializers.ModelSerializer):
    class Meta:
        model = MainBoard
        fields = '__all__'

def GenericGeneratorSerializer(modell,cerealizer,fieldss='__all__'):
    class GenericSerializer(cerealizer):
        class Meta:
            model = modell
            fields = fieldss
    return GenericSerializer

