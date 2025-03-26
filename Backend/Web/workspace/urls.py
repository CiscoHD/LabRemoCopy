from django.urls import path, include
from rest_framework.routers import DefaultRouter

from .views import (
    ### Component VIEWS
    # ComponentListCreateView,
    # ComponentRetrieveAPIView,
    # ComponentRetrieveUpdateView,
    # ComponentDestroyAPIView,
    ### CompoentList VIEWS
    # ComponentListListCreateView,
    # ComponentListRetrieveAPIView,
    # ComponentListRetrieveUpdateView,
    # ComponentListDestroyAPIView,
    ### MainBoard VIEWS
    # MainBoardListCreateView,
    # MainBoardRetrieveAPIView,
    # MainBoardRetrieveUpdateView,
    # MainBoardDestroyAPIView,
    ### Contratos VIEWS
    ComponenteViewSet,
    ContratosListCreateView,
    ContratosRetrieveAPIView,
    ContratosRetrieveUpdateView,
    ContratosDestroyAPIView,
    TipoComponenteViewSet,
    TransaccionesDestroyAPIView,
    TransaccionesListCreateView,
    TransaccionesRetrieveAPIView,
    TransaccionesRetrieveUpdateView,
)

component = 'component/'
componentList = 'component_list/'
mainboard = 'mainboard/'
contratos = 'contratos/'
transacciones = 'transacciones/'


# Crear el router
router = DefaultRouter()

# Registrar los ViewSets
router.register(r'tipos-componente', TipoComponenteViewSet, basename='tipocomponente')
router.register(r'componentes', ComponenteViewSet, basename='componente')

urlpatterns = [

    path('', include(router.urls)),
    ##############################################################
    ### Component API
    ##############################################################
    # path(component+'',ComponentListCreateView.as_view(),name='component_list_create'),
    # path(component+'<str:id>/',ComponentRetrieveAPIView.as_view(),name='component_detail'),
    # path(component+'update/<str:id>/', ComponentRetrieveUpdateView.as_view(),name='component_update'),
    # path(component+'delete/<str:id>', ComponentDestroyAPIView.as_view()),
    # ##############################################################
    # ### CompoentList API
    # ##############################################################
    # path(componentList+'',ComponentListListCreateView.as_view()),
    # path(componentList+'<str:id>/',ComponentListRetrieveAPIView.as_view(),name='componentlist_detail'),
    # path(componentList+'update/<str:id>/', ComponentListRetrieveUpdateView.as_view(),name='componentlist_update'),
    # path(componentList+'delete/<str:id>', ComponentListDestroyAPIView.as_view(),name='componentlist_destroy'),
    # ##############################################################
    # ### MainBoard API
    # ##############################################################
    # path(mainboard+'',MainBoardListCreateView.as_view()),
    # path(mainboard+'<str:id>/',MainBoardRetrieveAPIView.as_view(),name='mainboard_detail'),
    # path(mainboard+'update/<str:id>/', MainBoardRetrieveUpdateView.as_view(),name='mainboard_update'),
    # path(mainboard+'delete/<str:id>', MainBoardDestroyAPIView.as_view(),name='mainboard_destroy'),
    ##############################################################
    ### Contratos API
    ##############################################################
    path(contratos+'',ContratosListCreateView.as_view()),
    path(contratos+'<str:id>/',ContratosRetrieveAPIView.as_view(),name='contratos_detail'),
    path(contratos+'update/<str:id>/', ContratosRetrieveUpdateView.as_view(),name='contratos_update'),
    path(contratos+'delete/<str:id>', ContratosDestroyAPIView.as_view(),name='contratos_destroy'),
   ##############################################################
    ### TransaccionesAuditor API
    ##############################################################
    path(transacciones+'',TransaccionesListCreateView.as_view()),
    path(transacciones+'<str:id>/',TransaccionesRetrieveAPIView.as_view(),name='transacciones_detail'),
    path(transacciones+'update/<str:id>/', TransaccionesRetrieveUpdateView.as_view(),name='transacciones_update'),
    path(transacciones+'delete/<str:id>', TransaccionesDestroyAPIView.as_view(),name='transacciones_destroy'),
]