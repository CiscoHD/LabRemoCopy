from django.urls import path, include
from .views import (
    ### Component VIEWS
    ComponentListCreateView,
    ComponentRetrieveAPIView,
    ComponentRetrieveUpdateView,
    ComponentDestroyAPIView,
    ### CompoentList VIEWS
    ComponentListListCreateView,
    ComponentListRetrieveAPIView,
    ComponentListRetrieveUpdateView,
    ComponentListDestroyAPIView,
    ### MainBoard VIEWS
    MainBoardListCreateView,
    MainBoardRetrieveAPIView,
    MainBoardRetrieveUpdateView,
    MainBoardDestroyAPIView,
)

component = 'component/'
componentList = 'component_list/'
mainboard = 'mainboard/'

urlpatterns = [
    ##############################################################
    ### Component API
    ##############################################################
    path(component+'',ComponentListCreateView.as_view(),name='component_list_create'),
    path(component+'<str:id>/',ComponentRetrieveAPIView.as_view(),name='component_detail'),
    path(component+'update/<str:id>/', ComponentRetrieveUpdateView.as_view(),name='component_update'),
    path(component+'delete/<str:id>', ComponentDestroyAPIView.as_view()),
    ##############################################################
    ### CompoentList API
    ##############################################################
    path(componentList+'',ComponentListListCreateView.as_view()),
    path(componentList+'<str:id>/',ComponentListRetrieveAPIView.as_view(),name='componentlist_detail'),
    path(componentList+'update/<str:id>/', ComponentListRetrieveUpdateView.as_view(),name='componentlist_update'),
    path(componentList+'delete/<str:id>', ComponentListDestroyAPIView.as_view(),name='componentlist_destroy'),
    ##############################################################
    ### MainBoard API
    ##############################################################
    path(mainboard+'',MainBoardListCreateView.as_view()),
    path(mainboard+'<str:id>/',MainBoardRetrieveAPIView.as_view(),name='mainboard_detail'),
    path(mainboard+'update/<str:id>/', MainBoardRetrieveUpdateView.as_view(),name='mainboard_update'),
    path(mainboard+'delete/<str:id>', MainBoardDestroyAPIView.as_view(),name='mainboard_destroy'),
]