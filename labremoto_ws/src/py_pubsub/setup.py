from setuptools import find_packages, setup

package_name = 'py_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='trabajo',
    maintainer_email='trabajo@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
'console_scripts': [
                'action_cliente_server = py_pubsub.action_cliente_server.py:main',
                'arduino_inf_cliente = py_pubsub.arduino_inf_cliente.py:main',
                'arduino_infrastructure = py_pubsub.arduino_infrastructure.py:main',
                'arduino = py_pubsub.arduino.py:main',
                'carga_bit = py_pubsub.carga_bit.py:main',
                'client_member_function = py_pubsub.client_member_function.py:main',
                'fibonacci_action_server = py_pubsub.fibonacci_action_server.py:main',
                'publicador_prueba = py_pubsub.publicador_prueba.py:main',
                'publisher_member_function = py_pubsub.publisher_member_function.py:main',
                'SendTran_Cliente = py_pubsub.SendTran_Cliente.py:main',
                'SendTran_Service = py_pubsub.SendTran_Service.py:main',
                'service_member_function = py_pubsub.service_member_function.py:main',
                'sesiones = py_pubsub.sesiones.py:main',
                'subscriber_member_function = py_pubsub.subscriber_member_function.py:main',
                'supervisor = py_pubsub.supervisor.py:main',
                'transform_vhdl_bit = py_pubsub.transform_vhdl_bit.py:main',
        ],
    },
)
