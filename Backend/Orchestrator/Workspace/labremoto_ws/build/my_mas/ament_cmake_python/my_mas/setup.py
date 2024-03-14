from setuptools import find_packages
from setuptools import setup

setup(
    name='my_mas',
    version='0.0.0',
    packages=find_packages(
        include=('my_mas', 'my_mas.*')),
)
