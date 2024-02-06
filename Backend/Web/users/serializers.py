from rest_framework import serializers, generics
from .models import (Activity, AuthorLabSessions, Country, DuinoFile, LabSessions, Professor, Student, StudentLabSession, Subject, UploadedFile, User, Careers,
                     Universities,Schools,Course,Roster, UserType)


class UserListSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['id','username','email','password','isAvailable','userType']
        ###########################################################
        ### por definir si isAvailable se queda solo modificable
        ### por un administrador
        ###########################################################

        extra_kwargs = {
            'password':{'write_only':True}
        }
    
    def create(self, validated_data):
        password = validated_data.pop('password',None)
        instance = self.Meta.model(**validated_data)
        if password is not None:
            instance.set_password(password)
        instance.save()
        return instance

class UserDetailSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = [
            'id',
            'username',
            'email',
            'password',
            'isAvailable',
            'userType',
        ]
        extra_kwargs = {
            'password':{'write_only':True}
        }

    def create(self, validated_data):
        password = validated_data.pop('password',None)
        instance = self.Meta.model(**validated_data)
        if password is not None:
            instance.set_password(password)
        instance.save()
        return instance
    
#### Serializers Subjects
class SubjectListCreateSerializer(serializers.ModelSerializer):
    class Meta:
        model = Subject
        fields = '__all__'
        
class SubjectDetailSerializer(serializers.ModelSerializer):
    class Meta:
        model = Subject
        fields = '__all__'

def GenericGeneratorSerializer(modell,cerealizer,fieldss='__all__'):
    class GenericSerializer(cerealizer):
        class Meta:
            model = modell
            fields = fieldss
    return GenericSerializer

CareersListCreateSerializer = GenericGeneratorSerializer(Careers,serializers.ModelSerializer)
CareersDetailSerializer = GenericGeneratorSerializer(Careers,serializers.ModelSerializer)

CountriesListCreateSerializer = GenericGeneratorSerializer(Country,serializers.ModelSerializer)
CountriesDetailSerializer = GenericGeneratorSerializer(Country,serializers.ModelSerializer)

UniversitiesListCreateSerializer = GenericGeneratorSerializer(Universities,serializers.ModelSerializer)
UniversitiesDetailSerializer = GenericGeneratorSerializer(Universities,serializers.ModelSerializer)

SchoolsListCreateSerializer = GenericGeneratorSerializer(Schools,serializers.ModelSerializer)
SchoolsDetailSerializer = GenericGeneratorSerializer(Schools,serializers.ModelSerializer)

ProfessorListCreateSerializer = GenericGeneratorSerializer(Professor,serializers.ModelSerializer)
ProfessorDetailSerializer = GenericGeneratorSerializer(Professor,serializers.ModelSerializer)

StudentListCreateSerializer = GenericGeneratorSerializer(Student,serializers.ModelSerializer)
StudentDetailSerializer = GenericGeneratorSerializer(Student,serializers.ModelSerializer)

CourseListCreateSerializer = GenericGeneratorSerializer(Course,serializers.ModelSerializer)
CourseDetailSerializer = GenericGeneratorSerializer(Course,serializers.ModelSerializer)

RosterListCreateSerializer = GenericGeneratorSerializer(Roster,serializers.ModelSerializer)
RosterDetailSerializer = GenericGeneratorSerializer(Roster,serializers.ModelSerializer)

UserTypeListCreateSerializer = GenericGeneratorSerializer(UserType,serializers.ModelSerializer)
UserTypeDetailSerializer = GenericGeneratorSerializer(UserType,serializers.ModelSerializer)

LabSessionsListCreateSerializer = GenericGeneratorSerializer(LabSessions,serializers.ModelSerializer)
LabSessionsDetailSerializer = GenericGeneratorSerializer(LabSessions,serializers.ModelSerializer)

AuthorLabSessionsListCreateSerializer = GenericGeneratorSerializer(AuthorLabSessions,serializers.ModelSerializer)
AuthorLabSessionsDetailSerializer = GenericGeneratorSerializer(AuthorLabSessions,serializers.ModelSerializer)

StudentLabSessionListCreateSerializer = GenericGeneratorSerializer(StudentLabSession,serializers.ModelSerializer)
StudentLabSessionDetailSerializer = GenericGeneratorSerializer(StudentLabSession,serializers.ModelSerializer)


ActivityListCreateSerializer = GenericGeneratorSerializer(Activity,serializers.ModelSerializer)
ActivityDetailSerializer = GenericGeneratorSerializer(Activity,serializers.ModelSerializer)


class UploadSerializer(serializers.Serializer):
    file = serializers.FileField()

    class Meta:
        model = DuinoFile
        fields = '__all__'


class userInfoSerializer(serializers.Serializer):
    class Meta:
        model = User
        fields = ['id','username','email','password','isAvailable','userType']


class FileUploadSerializer(serializers.ModelSerializer):
    class Meta:
        model = UploadedFile
        fields = ('file','uploaded_on',)