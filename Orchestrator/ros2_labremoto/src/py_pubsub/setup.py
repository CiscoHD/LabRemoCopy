from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'py_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ffelix07',
    maintainer_email='ffelix07@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    
    entry_points={
        'console_scripts': [
                'supervisor_operaciones = py_pubsub.supervisor_operaciones:main',
                'auditor_transacciones = py_pubsub.auditor_transacciones:main',
                'publisher_prueba = py_pubsub.publisher_prueba:main',
                'admin_contratos = py_pubsub.admin_contratos: main',
                'admin_transacciones = py_pubsub.admin_transacciones:main',
                'arduino_infrastructure = py_pubsub.arduino_infrastructure:main',
                'arduino_inf_cliente = py_pubsub.arduino_inf_cliente:main',
                'transform_vhdl_bit = py_pubsub.transform_vhdl_bit:main',
                'action_cliente_server = py_pubsub.action_cliente_server:main'
        ],
},
)