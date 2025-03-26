from django.shortcuts import render

from rest_framework import exceptions,generics, serializers,viewsets
from rest_framework.permissions import IsAdminUser, IsAuthenticated

from .models import (
                    # Component,
                    #  ComponentList,
                    #  MainBoard,
                     Contratos,
                     TransaccionesAuditor,
                     Componente,
                     TipoComponente
                     )
from .serializers import (
                            # ComponentSerializer,
                            # ComponentListSerializer,
                            # MainBoardSerializer,
                            TransaccionesSerializer,
                            ContratosSerializer,
                            ComponenteSerializer,
                            TipoComponenteSerializer
                            )


DEBUG = True
PERMISSIONS_ADMIN = [] if DEBUG else [IsAdminUser]
PERMISSIONS_AUTHEN = [] if DEBUG else [IsAuthenticated]


class TipoComponenteViewSet(viewsets.ModelViewSet):
    queryset = TipoComponente.objects.all().order_by('nombre')
    serializer_class = TipoComponenteSerializer
    pagination_class = None

    def get_permissions(self):
        # Admin para operaciones de escritura, autenticados para lectura
        if self.action in ['list', 'retrieve']:
            self.permission_classes = PERMISSIONS_AUTHEN
        else:
            self.permission_classes = PERMISSIONS_ADMIN
        return super().get_permissions()

class ComponenteViewSet(viewsets.ModelViewSet):
    queryset = Componente.objects.all().order_by('nombre')
    serializer_class = ComponenteSerializer
    
    def get_permissions(self):
        # Mismo esquema de permisos que TipoComponente
        if self.action in ['list', 'retrieve']:
            self.permission_classes = PERMISSIONS_AUTHEN
        else:
            self.permission_classes = PERMISSIONS_ADMIN
        return super().get_permissions()
    
    def get_queryset(self):
        queryset = super().get_queryset()
        tipo_id = self.request.query_params.get('tipo_id')
        if tipo_id:
            queryset = queryset.filter(tipo_id=tipo_id)
        return queryset
    
    def list(self, request, *args, **kwargs):
        if request.query_params.get('all', '').lower() == 'true':
            self.pagination_class = None
        return super().list(request, *args, **kwargs)


###############################################################
####    ComponentList 
###############################################################

# class ComponentListListCreateView(generics.ListCreateAPIView):
#     """API endpoint for listing and creating users"""
#     #permission_classes = PERMISSIONS_ADMIN
#     queryset = ComponentList.objects.all()
#     serializer_class = ComponentListSerializer

#     def get_permissions(self):
#         self.permission_classes = PERMISSIONS_ADMIN
#         if self.request.method == 'GET':
#             self.permission_classes = PERMISSIONS_AUTHEN
#         return super(ComponentListListCreateView,self).get_permissions()

# class ComponentListRetrieveAPIView(generics.RetrieveAPIView):
#     """API endpoint for listing detailed users"""
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = ComponentList.objects.all()
#     serializer_class = ComponentListSerializer

# class ComponentListRetrieveUpdateView(generics.RetrieveUpdateAPIView):
#     """API endpoint for updating detailed users"""
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = ComponentList.objects.all()
#     serializer_class = ComponentListSerializer

# class ComponentListDestroyAPIView(generics.DestroyAPIView):
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = ComponentList.objects.all()
#     serializer_class = ComponentListSerializer
    
    
###############################################################
####    MainBoard 
###############################################################

# class MainBoardListCreateView(generics.ListCreateAPIView):
#     """API endpoint for listing and creating users"""
#     #permission_classes = PERMISSIONS_ADMIN
#     queryset = MainBoard.objects.all()
#     serializer_class = MainBoardSerializer

#     def get_permissions(self):
#         self.permission_classes = PERMISSIONS_ADMIN
#         if self.request.method == 'GET':
#             self.permission_classes = PERMISSIONS_AUTHEN
#         return super(MainBoardListCreateView,self).get_permissions()

# class MainBoardRetrieveAPIView(generics.RetrieveAPIView):
#     """API endpoint for listing detailed users"""
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = MainBoard.objects.all()
#     serializer_class = MainBoardSerializer

# class MainBoardRetrieveUpdateView(generics.RetrieveUpdateAPIView):
#     """API endpoint for updating detailed users"""
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = MainBoard.objects.all()
#     serializer_class = MainBoardSerializer

# class MainBoardDestroyAPIView(generics.DestroyAPIView):
#     permission_classes = PERMISSIONS_ADMIN
#     lookup_field = 'id'
#     queryset = MainBoard.objects.all()
#     serializer_class = MainBoardSerializer

###############################################################
####    Contratos 
###############################################################

class ContratosListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating Contratos"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = Contratos.objects.all()
    serializer_class = ContratosSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(ContratosListCreateView,self).get_permissions()
    
class ContratosRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed Contratos"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Contratos.objects.all()
    serializer_class = ContratosSerializer

class ContratosRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed Contratos"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Contratos.objects.all()
    serializer_class = ContratosSerializer

class ContratosDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = Contratos.objects.all()
    serializer_class = ContratosSerializer


###############################################################
####    Transacciones auditor 
###############################################################

class TransaccionesListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating Transacciones"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = TransaccionesAuditor.objects.all()
    serializer_class = TransaccionesSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(TransaccionesListCreateView,self).get_permissions()
    
class TransaccionesRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed Transacciones"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = TransaccionesAuditor.objects.all()
    serializer_class = TransaccionesSerializer

class TransaccionesRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed Transacciones"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = TransaccionesAuditor.objects.all()
    serializer_class = TransaccionesSerializer

class TransaccionesDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = TransaccionesAuditor.objects.all()
    serializer_class = TransaccionesSerializer