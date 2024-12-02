from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'pnodos'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']), 
        (os.path.join('share', package_name), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            #Nodos de prueba -------------------------------------
            'publisher = pnodos.publisher:main',
            'subscriber = pnodos.subscriber:main',
            #Supervisores ---------------------------------------
            'supervisor = pnodos.supervisor:main',
            'databaser = pnodos.databaser:main',
            'auditor = pnodos.auditor:main',
            'administrator = pnodos.administrator:main',
            'exit_logger = pnodos.exit_logger:main',
            'transactioner = pnodos.transactioner:main',
            'input_transactioner = pnodos.input_transactioner:main',
            #Action ------------------------------------- HexCharge
            'arduino_inf_client = pnodos.arduino_inf_client:main',
            'arduino_inf_server = pnodos.arduino_inf_server:main',
            #Action ------------------------------------- BinCharge
            'esp32_inf_client = pnodos.esp32_inf_client:main',
            'esp32_inf_server = pnodos.esp32_inf_server:main'

        ],
    },
)
