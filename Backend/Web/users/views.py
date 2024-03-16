#from django.shortcuts import render
from django.db import models
from labRemoto.settings import DEBUG, ROOT_MEDIA

from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.permissions import IsAdminUser, IsAuthenticated
from rest_framework.parsers import FormParser, MultiPartParser
from rest_framework.response import Response
from rest_framework import exceptions,generics, serializers
from rest_framework.viewsets import ViewSet

from rest_framework.views import APIView

from .serializers import FileUploadSerializer


# from .models import DuinoFile


from .serializers import (
    ActivityDetailSerializer, ActivityListCreateSerializer, AuthorLabSessionsDetailSerializer, AuthorLabSessionsListCreateSerializer, CareersDetailSerializer, CareersListCreateSerializer, 
    CountriesDetailSerializer, CountriesListCreateSerializer, CourseDetailSerializer, CourseListCreateSerializer, LabSessionsDetailSerializer, LabSessionsListCreateSerializer, ProfessorDetailSerializer, ProfessorListCreateSerializer, RosterDetailSerializer, RosterListCreateSerializer, SchoolsDetailSerializer, SchoolsListCreateSerializer, StudentDetailSerializer, StudentLabSessionDetailSerializer, StudentLabSessionListCreateSerializer, StudentListCreateSerializer,
    SubjectDetailSerializer, SubjectListCreateSerializer, UniversitiesDetailSerializer, UniversitiesListCreateSerializer, 
    UserListSerializer,UserDetailSerializer, UserTypeDetailSerializer, UserTypeListCreateSerializer,
    #UploadSerializer,
    userInfoSerializer,
    )

from .models import Activity, AuthorLabSessions, Careers, Country, Course, LabSessions, Professor, Roster, Schools, Student, StudentLabSession, Subject, Universities, User, UserType

DEBUG = True
PERMISSIONS_ADMIN = [] if DEBUG else [IsAdminUser]
PERMISSIONS_AUTHEN = [] if DEBUG else [IsAuthenticated]

# Create your views here.

### Views of User
class UserListCreateView(generics.ListCreateAPIView):
    """API endpoint for listing and creating users"""
    #permission_classes = PERMISSIONS_ADMIN
    queryset = User.objects.all()
    serializer_class = UserListSerializer

    def get_permissions(self):
        self.permission_classes = PERMISSIONS_ADMIN
        if self.request.method == 'GET':
            self.permission_classes = PERMISSIONS_AUTHEN
        return super(UserListCreateView,self).get_permissions()

class UserRetrieveAPIView(generics.RetrieveAPIView):
    """API endpoint for listing detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = User.objects.all()
    serializer_class = UserDetailSerializer

class UserRetrieveUpdateView(generics.RetrieveUpdateAPIView):
    """API endpoint for updating detailed users"""
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = User.objects.all()
    serializer_class = UserDetailSerializer

class UserDestroyAPIView(generics.DestroyAPIView):
    permission_classes = PERMISSIONS_ADMIN
    lookup_field = 'id'
    queryset = User.objects.all()
    serializer_class = UserDetailSerializer


### Views of Subject
def GenericGeneratorAPIView(model,serializer,genAPI,permissions=PERMISSIONS_ADMIN):
    class GenericRetrieveAPIView(genAPI):
        """API endpoint for listing, creating, updating detailed or deleting """
        permission_classes = permissions
        if genAPI in [generics.RetrieveAPIView,generics.RetrieveUpdateAPIView,generics.DestroyAPIView]:
            lookup_field = 'id'
        queryset = model.objects.all()
        
        serializer_class = serializer

        def get_permissions(self):
            self.permission_classes = PERMISSIONS_ADMIN
            if self.request.method == 'GET':
                self.permission_classes = PERMISSIONS_AUTHEN
            return super(GenericRetrieveAPIView,self).get_permissions()
        
    return GenericRetrieveAPIView


SubjectListCreateView = GenericGeneratorAPIView(Subject,SubjectListCreateSerializer,generics.ListCreateAPIView)
SubjectRetrieveAPIView = GenericGeneratorAPIView(Subject,SubjectDetailSerializer,generics.RetrieveAPIView)
SubjectRetrieveUpdateAPIView = GenericGeneratorAPIView(Subject,SubjectDetailSerializer,generics.RetrieveUpdateAPIView)
SubjectDestroyAPIView = GenericGeneratorAPIView(Subject,SubjectDetailSerializer,generics.DestroyAPIView)


CareerListCreateView = GenericGeneratorAPIView(Careers, CareersListCreateSerializer, generics.ListCreateAPIView)
CareersRetrieveAPIView = GenericGeneratorAPIView(Careers,CareersDetailSerializer,generics.RetrieveAPIView)
CareersRetrieveUpdateAPIView = GenericGeneratorAPIView(Careers,CareersDetailSerializer,generics.RetrieveUpdateAPIView)
CareersDestroyAPIView = GenericGeneratorAPIView(Careers,CareersDetailSerializer,generics.DestroyAPIView)

CountryListCreateView = GenericGeneratorAPIView(Country, CountriesListCreateSerializer, generics.ListCreateAPIView)
CountryRetrieveAPIView = GenericGeneratorAPIView(Country,CountriesDetailSerializer,generics.RetrieveAPIView)
CountryRetrieveUpdateAPIView = GenericGeneratorAPIView(Country,CountriesDetailSerializer,generics.RetrieveUpdateAPIView)
CountryDestroyAPIView = GenericGeneratorAPIView(Country,CountriesDetailSerializer,generics.DestroyAPIView)

UniversitiesListCreateView = GenericGeneratorAPIView(Universities, UniversitiesListCreateSerializer, generics.ListCreateAPIView)
UniversitiesRetrieveAPIView = GenericGeneratorAPIView(Universities,UniversitiesDetailSerializer,generics.RetrieveAPIView)
UniversitiesRetrieveUpdateAPIView = GenericGeneratorAPIView(Universities,UniversitiesDetailSerializer,generics.RetrieveUpdateAPIView)
UniversitiesDestroyAPIView = GenericGeneratorAPIView(Universities,UniversitiesDetailSerializer,generics.DestroyAPIView)

SchoolsListCreateView = GenericGeneratorAPIView(Schools, SchoolsListCreateSerializer, generics.ListCreateAPIView)
SchoolsRetrieveAPIView = GenericGeneratorAPIView(Schools,SchoolsDetailSerializer,generics.RetrieveAPIView)
SchoolsRetrieveUpdateAPIView = GenericGeneratorAPIView(Schools,SchoolsDetailSerializer,generics.RetrieveUpdateAPIView)
SchoolsDestroyAPIView = GenericGeneratorAPIView(Schools,SchoolsDetailSerializer,generics.DestroyAPIView)

ProfessorListCreateView = GenericGeneratorAPIView(Professor, ProfessorListCreateSerializer, generics.ListCreateAPIView)
ProfessorRetrieveAPIView = GenericGeneratorAPIView(Professor,ProfessorDetailSerializer,generics.RetrieveAPIView)
ProfessorRetrieveUpdateAPIView = GenericGeneratorAPIView(Professor,ProfessorDetailSerializer,generics.RetrieveUpdateAPIView)
ProfessorDestroyAPIView = GenericGeneratorAPIView(Professor,ProfessorDetailSerializer,generics.DestroyAPIView)

StudentListCreateView = GenericGeneratorAPIView(Student, StudentListCreateSerializer, generics.ListCreateAPIView)
StudentRetrieveAPIView = GenericGeneratorAPIView(Student,StudentDetailSerializer,generics.RetrieveAPIView)
StudentRetrieveUpdateAPIView = GenericGeneratorAPIView(Student,StudentDetailSerializer,generics.RetrieveUpdateAPIView)
StudentDestroyAPIView = GenericGeneratorAPIView(Student,StudentDetailSerializer,generics.DestroyAPIView)

CourseListCreateView = GenericGeneratorAPIView(Course, CourseListCreateSerializer, generics.ListCreateAPIView)
CourseRetrieveAPIView = GenericGeneratorAPIView(Course,CourseDetailSerializer,generics.RetrieveAPIView)
CourseRetrieveUpdateAPIView = GenericGeneratorAPIView(Course,CourseDetailSerializer,generics.RetrieveUpdateAPIView)
CourseDestroyAPIView = GenericGeneratorAPIView(Course,CourseDetailSerializer,generics.DestroyAPIView)

RosterListCreateView = GenericGeneratorAPIView(Roster, RosterListCreateSerializer, generics.ListCreateAPIView)
RosterRetrieveAPIView = GenericGeneratorAPIView(Roster,RosterDetailSerializer,generics.RetrieveAPIView)
RosterRetrieveUpdateAPIView = GenericGeneratorAPIView(Roster,RosterDetailSerializer,generics.RetrieveUpdateAPIView)
RosterDestroyAPIView = GenericGeneratorAPIView(Roster,RosterDetailSerializer,generics.DestroyAPIView)

UserTypeListCreateView = GenericGeneratorAPIView(UserType, UserTypeListCreateSerializer, generics.ListCreateAPIView)
UserTypeRetrieveAPIView = GenericGeneratorAPIView(UserType,UserTypeDetailSerializer,generics.RetrieveAPIView)
UserTypeRetrieveUpdateAPIView = GenericGeneratorAPIView(UserType,UserTypeDetailSerializer,generics.RetrieveUpdateAPIView)
UserTypeDestroyAPIView = GenericGeneratorAPIView(UserType,UserTypeDetailSerializer,generics.DestroyAPIView)

LabSessionsListCreateView = GenericGeneratorAPIView(LabSessions, LabSessionsListCreateSerializer, generics.ListCreateAPIView)
LabSessionsRetrieveAPIView = GenericGeneratorAPIView(LabSessions,LabSessionsDetailSerializer,generics.RetrieveAPIView)
LabSessionsRetrieveUpdateAPIView = GenericGeneratorAPIView(LabSessions,LabSessionsDetailSerializer,generics.RetrieveUpdateAPIView)
LabSessionsDestroyAPIView = GenericGeneratorAPIView(LabSessions,LabSessionsDetailSerializer,generics.DestroyAPIView)

AuthorLabSessionsListCreateView = GenericGeneratorAPIView(AuthorLabSessions, AuthorLabSessionsListCreateSerializer, generics.ListCreateAPIView)
AuthorLabSessionsRetrieveAPIView = GenericGeneratorAPIView(AuthorLabSessions,AuthorLabSessionsDetailSerializer,generics.RetrieveAPIView)
AuthorLabSessionsRetrieveUpdateAPIView = GenericGeneratorAPIView(AuthorLabSessions,AuthorLabSessionsDetailSerializer,generics.RetrieveUpdateAPIView)
AuthorLabSessionsDestroyAPIView = GenericGeneratorAPIView(AuthorLabSessions,AuthorLabSessionsDetailSerializer,generics.DestroyAPIView)

StudentLabSessionListCreateView = GenericGeneratorAPIView(StudentLabSession, StudentLabSessionListCreateSerializer, generics.ListCreateAPIView)
StudentLabSessionRetrieveAPIView = GenericGeneratorAPIView(StudentLabSession,StudentLabSessionDetailSerializer,generics.RetrieveAPIView)
StudentLabSessionRetrieveUpdateAPIView = GenericGeneratorAPIView(StudentLabSession,StudentLabSessionDetailSerializer,generics.RetrieveUpdateAPIView)
StudentLabSessionDestroyAPIView = GenericGeneratorAPIView(StudentLabSession,StudentLabSessionDetailSerializer,generics.DestroyAPIView)


ActivityListCreateView = GenericGeneratorAPIView(Activity, ActivityListCreateSerializer, generics.ListCreateAPIView)
ActivityRetrieveAPIView = GenericGeneratorAPIView(Activity,ActivityDetailSerializer,generics.RetrieveAPIView)
ActivityRetrieveUpdateAPIView = GenericGeneratorAPIView(Activity,ActivityDetailSerializer,generics.RetrieveUpdateAPIView)
ActivityDestroyAPIView = GenericGeneratorAPIView(Activity,ActivityDetailSerializer,generics.DestroyAPIView)


# class UploadViewSet(generics.ListCreateAPIView):
#     queryset = DuinoFile.objects.all()
#     serializer_class = UploadSerializer

    # """def list(self, request):
    #     return Response("GET API")"""
    # """
    # def create(self, request):
    #     file_uploaded = request.FILES.get('file')
    #     content_type = file_uploaded.content_type
    #     with open(ROOT_MEDIA+'{}'.format(file_uploaded.name),'wb') as destination:
    #         for chunk in file_uploaded.chunks():
    #             destination.write(chunk)
    #     response = "POST API and you have uploaded a {} file".format(content_type)
    #     return Response(response)
    # """
    # """def post(self,request):
    #     up_file = request.FILES['file_uploaded']
    #     with open('/{}'.format(up_file.name,'wb')) as destination:
    #         for chunk in up_file.chunks():
    #             destination.write(chunk)
    #         #destination.close()

    #     return Response(up_file.name, status.HTTP_201_CREATED)"""


class userDetail(generics.ListAPIView):
    queryset = User.objects.all()
    serializer_class = UserListSerializer
    
    def list(self,request):
        if request.user.is_anonymous != True:
            queryset = User.objects.filter(id=request.user.id)
            response = UserListSerializer(queryset,many=True)
            #return Response('{}'.format(request.user.id))
            response = response.data
        else:
            response = "User not authenticated, please login!!"
        return Response(response)


class FileUploadAPIView(APIView):
    parser_classes = (MultiPartParser, FormParser)
    serializer_class = FileUploadSerializer
    
    def post(self,request, *args, **kwargs):
        serializer = self.serializer_class(data=request.data)
        if serializer.is_valid():
            ## saving data
            serializer.save()
            return Response(
                serializer.data,
                status=status.HTTP_201_CREATED
            )
        return Response(
            serializer.errors,
            status=status.HTTP_400_BAD_REQUEST
        )