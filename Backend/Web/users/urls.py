from django.urls import path, include
from .views import (
    ActivityDestroyAPIView, ActivityListCreateView, ActivityRetrieveAPIView, ActivityRetrieveUpdateAPIView, AuthorLabSessionsDestroyAPIView, AuthorLabSessionsListCreateView, AuthorLabSessionsRetrieveAPIView, AuthorLabSessionsRetrieveUpdateAPIView, CourseDestroyAPIView, CourseListCreateView, CourseRetrieveAPIView, CourseRetrieveUpdateAPIView, FileUploadAPIView, LabSessionsDestroyAPIView, LabSessionsListCreateView, LabSessionsRetrieveAPIView, LabSessionsRetrieveUpdateAPIView, ProfessorDestroyAPIView, ProfessorListCreateView, ProfessorRetrieveAPIView, ProfessorRetrieveUpdateAPIView, RosterDestroyAPIView, RosterListCreateView, RosterRetrieveAPIView, RosterRetrieveUpdateAPIView, SchoolsDestroyAPIView, SchoolsListCreateView, SchoolsRetrieveAPIView, SchoolsRetrieveUpdateAPIView, StudentDestroyAPIView, StudentLabSessionDestroyAPIView, StudentLabSessionListCreateView, StudentLabSessionRetrieveAPIView, StudentLabSessionRetrieveUpdateAPIView, StudentListCreateView, StudentRetrieveAPIView, StudentRetrieveUpdateAPIView, UniversitiesDestroyAPIView, UniversitiesListCreateView, UniversitiesRetrieveAPIView, UniversitiesRetrieveUpdateAPIView, UserDestroyAPIView, UserRetrieveAPIView, 
    UserListCreateView, UserRetrieveUpdateView,
    ### API Subject
    SubjectListCreateView,SubjectRetrieveAPIView, 
    SubjectRetrieveUpdateAPIView,SubjectDestroyAPIView,
    ### API Careers
    CareerListCreateView,CareersDestroyAPIView, CareersRetrieveAPIView,
    CareersRetrieveUpdateAPIView,
    ### API Countries
    CountryDestroyAPIView, CountryListCreateView, CountryRetrieveAPIView,
    CountryRetrieveUpdateAPIView, UserTypeDestroyAPIView, UserTypeListCreateView, UserTypeRetrieveAPIView, UserTypeRetrieveUpdateAPIView,

    # UploadViewSet,
    userDetail
)

str_users = 'users/'
str_subjects = 'subjects/'
str_careers = 'careers/'
str_countries = 'countries/'
str_universities = 'universities/'
str_schools = 'schools/'
str_professor = 'professor/'
str_student = 'student/'
str_course = 'course/'
str_roster = 'roster/'
str_usertype = 'userType/'
str_labsessions = 'labSessions/'
str_authorlabsessions = 'authorLabSessions/'
str_studentlabsession = 'studentLabSession/'

str_users = 'cat'+'Users/'
str_subjects = 'cat'+'Subjects/'
str_careers = 'cat'+ 'Careers/'
str_countries = 'cat'+ 'Countries/'
str_universities = 'cat'+ 'Universities/'
str_schools = 'cat'+ 'Schools/'
str_professor = 'cat'+ 'Professor/'
str_student = 'cat'+ 'Student/'
str_labsessions = 'catLabsessions/'
str_usertype = 'catUserType/'
str_roster = 'classRoster/'

str_activity = 'activity/'




urlpatterns = [
    ##############################################################
    ### Users API
    ##############################################################
    path(str_users+'',UserListCreateView.as_view(),name='user_list_create'),
    path(str_users+'<str:id>/',UserRetrieveAPIView.as_view(),name='user_detail'),
    path(str_users+'update/<str:id>/', UserRetrieveUpdateView.as_view(),name='user_update'),
    path(str_users+'delete/<str:id>', UserDestroyAPIView.as_view()),
    ##############################################################
    ### Subjects API
    ##############################################################
    path(str_subjects+'',SubjectListCreateView.as_view()),
    path(str_subjects+'<str:id>/',SubjectRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_subjects+'update/<str:id>/', SubjectRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_subjects+'delete/<str:id>', SubjectDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Careers API
    ##############################################################
    path(str_careers+'',CareerListCreateView.as_view()),
    path(str_careers+'<str:id>/',CareersRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_careers+'update/<str:id>/', CareersRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_careers+'delete/<str:id>', CareersDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Countries API
    ##############################################################
    path(str_countries+'',CountryListCreateView.as_view()),
    path(str_countries+'<str:id>/',CountryRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_countries+'update/<str:id>/', CountryRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_countries+'delete/<str:id>', CountryDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Universities API
    ##############################################################
    path(str_universities+'',UniversitiesListCreateView.as_view()),
    path(str_universities+'<str:id>/',UniversitiesRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_universities+'update/<str:id>/', UniversitiesRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_universities+'delete/<str:id>', UniversitiesDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Schools API
    ##############################################################
    path(str_schools+'',SchoolsListCreateView.as_view()),
    path(str_schools+'<str:id>/',SchoolsRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_schools+'update/<str:id>/', SchoolsRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_schools+'delete/<str:id>', SchoolsDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Professor API
    ##############################################################
    path(str_professor+'',ProfessorListCreateView.as_view()),
    path(str_professor+'<str:id>/',ProfessorRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_professor+'update/<str:id>/', ProfessorRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_professor+'delete/<str:id>', ProfessorDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Student API
    ##############################################################
    path(str_student+'',StudentListCreateView.as_view()),
    path(str_student+'<str:id>/',StudentRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_student+'update/<str:id>/', StudentRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_student+'delete/<str:id>', StudentDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Course API
    ##############################################################
    path(str_course+'',CourseListCreateView.as_view()),
    path(str_course+'<str:id>/',CourseRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_course+'update/<str:id>/', CourseRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_course+'delete/<str:id>', CourseDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### Roster API
    ##############################################################
    path(str_roster+'',RosterListCreateView.as_view()),
    path(str_roster+'<str:id>/',RosterRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_roster+'update/<str:id>/', RosterRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_roster+'delete/<str:id>', RosterDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### UserType API
    ##############################################################
    path(str_usertype+'',UserTypeListCreateView.as_view()),
    path(str_usertype+'<str:id>/',UserTypeRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_usertype+'update/<str:id>/', UserTypeRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_usertype+'delete/<str:id>', UserTypeDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### LabSessions API
    ##############################################################
    path(str_labsessions+'',LabSessionsListCreateView.as_view()),
    path(str_labsessions+'<str:id>/',LabSessionsRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_labsessions+'update/<str:id>/', LabSessionsRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_labsessions+'delete/<str:id>', LabSessionsDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### AuthorLabSessions API
    ##############################################################
    path(str_authorlabsessions+'',AuthorLabSessionsListCreateView.as_view()),
    path(str_authorlabsessions+'<str:id>/',AuthorLabSessionsRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_authorlabsessions+'update/<str:id>/', AuthorLabSessionsRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_authorlabsessions+'delete/<str:id>', AuthorLabSessionsDestroyAPIView.as_view(),name='subject_destroy'),
    ##############################################################
    ### StudentLabSession API
    ##############################################################
    path(str_studentlabsession+'',StudentLabSessionListCreateView.as_view()),
    path(str_studentlabsession+'<str:id>/',StudentLabSessionRetrieveAPIView.as_view(),name='subject_detail'),
    path(str_studentlabsession+'update/<str:id>/', StudentLabSessionRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(str_studentlabsession+'delete/<str:id>', StudentLabSessionDestroyAPIView.as_view(),name='subject_destroy'),

    ##############################################################
    ### Activity API
    ##############################################################
    path(    str_activity+'',ActivityListCreateView.as_view()),
    path(    str_activity+'<str:id>/',ActivityRetrieveAPIView.as_view(),name='subject_detail'),
    path(    str_activity+'update/<str:id>/', ActivityRetrieveUpdateAPIView.as_view(),name='subject_update'),
    path(    str_activity+'delete/<str:id>', ActivityDestroyAPIView.as_view(),name='subject_destroy'),


    # path('upload', UploadViewSet.as_view(), name="upload"),
    path('upload2', FileUploadAPIView.as_view(), name="upload-file"),


    path('userInfo/',userDetail.as_view(), name="user_info"),

]