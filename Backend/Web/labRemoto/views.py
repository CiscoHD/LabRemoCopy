from django.contrib.auth.models import User, Group
#from profiles import models as profileModels

from labRemoto import serializers as labSerializers
from rest_framework import generics, permissions, serializers
from oauth2_provider.contrib.rest_framework import TokenHasReadWriteScope, TokenHasScope


