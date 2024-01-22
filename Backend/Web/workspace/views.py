from django.shortcuts import render

from rest_framework import exceptions,generics, serializers
from rest_framework.permissions import IsAdminUser, IsAuthenticated

from .models import (Component,
                     ComponentList,
                     MainBoard)
from .serializers import (ComponentSerializer,
                            ComponentListSerializer,
                            MainBoardSerializer)


DEBUG = False
PERMISSIONS_ADMIN = [] if DEBUG else [IsAdminUser]
PERMISSIONS_AUTHEN = [] if DEBUG else [IsAuthenticated]


# Create your views here.
class ComponentListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating users"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = Component.objects.all()
    serializer_class = ComponentListSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(ComponentListCreateView,self).get_permissions()

class ComponentRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Component.objects.all()
    serializer_class = ComponentSerializer

class ComponentRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Component.objects.all()
    serializer_class = ComponentSerializer

class ComponentDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Component.objects.all()
    serializer_class = ComponentSerializer


###############################################################
####    ComponentList 
###############################################################

class ComponentListListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating users"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = ComponentList.objects.all()
    serializer_class = ComponentListSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(ComponentListListCreateView,self).get_permissions()

class ComponentListRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = ComponentList.objects.all()
    serializer_class = ComponentListSerializer

class ComponentListRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = ComponentList.objects.all()
    serializer_class = ComponentListSerializer

class ComponentListDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = ComponentList.objects.all()
    serializer_class = ComponentListSerializer
    
    
###############################################################
####    MainBoard 
###############################################################

class MainBoardListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating users"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = MainBoard.objects.all()
    serializer_class = MainBoardSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(MainBoardListCreateView,self).get_permissions()

class MainBoardRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = MainBoard.objects.all()
    serializer_class = MainBoardSerializer

class MainBoardRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = MainBoard.objects.all()
    serializer_class = MainBoardSerializer

class MainBoardDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = MainBoard.objects.all()
    serializer_class = MainBoardSerializer