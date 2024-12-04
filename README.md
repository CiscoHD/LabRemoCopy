# Laboratorio Remoto con ROS2 HUMBLE
laboratorio_remo_remasterizado
**Using ros2 humble on ubuntu 22.04**

# Commands to init the nodes (v0.3.9)

_In the directory before LabRemo/_ execute the command: `python3 -m virtualenv LabRemo/` to init the virtual enviroment

_In the directory LabRemo/_

* `source bin/activate` For the virtual enviroment activation

_In the same directory_

* `pip install -r requirements.txt` For install the dependencies (**Only the first time**)

_In the same directory_

* `pip freeze > requirements.txt` For save the new dependencies in the requirements.txt file (**Only if there are new dependencies on project**)

_In the directory labremoto/ros_ws/_

* `ros2 launch pnodos nodos_log.launch.py`

Then...

* `ros2 launch pnodos nodos_inicio.launch.py` For activate the actions (v0.3.0:**Now just the arduino action**)

# Extra installations

* **Arduino Cli** To use the arduino commands `https://arduino.github.io/arduino-cli/1.0/installation/`

* **ESPTOOL.PY** To use the esp32 microcontroller `pip install esptool.py`

* **RSHELL** To use the raspberry and connect to its console `sudo apt install pyboard-rshell`

    ~~~
    rshell -p /dev/raspberry #To connect to the raspberry

    repl #To execute the python enviorement

    import {file_path} #To execute the python script
    ~~~

# Extra configurations

* Add this command to ~/.bashrc (_Autoexecution in new terminal)_

    ~~~
    source /laboratorio_remo_remasterizado/labremoto/ros_ws/install/setup.bash
    ~~~

* Port custom names (Give custom names and use them)

    - First: Check the _productId_ and the _vendorId_ returned by the command: `lsusb`. For example:

        ~~~
        Device 001: ID 1d6b:0002 // -> // vendorId:productId
        ~~~

    - With this information, create a new rule in _99-arduino.rules_ file (using nano or another text editor)

        ~~~
        sudo nano /etc/udev/rules.d/99-arduino.rules
        ~~~

    - The rule name follows the next template: `SUBSYSTEM=="tty", ATTRS{idVendor}=="`**_vendorID_**`", ATTRS{idProduct}=="`**_productID_**`", SYMLINK+="`**_customName_**`"`.For example (Using it now for the microcontrollers):

        ~~~
        SUBSYSTEM=="tty", ATTRS{idVendor}=="1a86", ATTRS{idProduct}=="7523", SYMLINK+="arduino_uno"
        SUBSYSTEM=="tty", ATTRS{idVendor}=="10c4", ATTRS{idProduct}=="ea60", SYMLINK+="esp32"
        SUBSYSTEM=="tty", ATTRS{idVendor}=="2e8a", ATTRS{idProduct}=="0005", SYMLINK+="raspberry"
        ~~~

# 🔴Remaining tasks (!) | V 0.4.0

* Install the `openFPGALoader` command

* Install the `vivado` command

* Create the `.tcl` script to _FPGA_ action to check the connected devices

* Add the node _FPGA_ actions (_client and server_) to the launcher *nodos_inicio.launch.py*

* Test the _FPGA_ action and commands

## Version 0 

### Directory structure

* *laboratorio_remo_remasterizado/*

In this directory was created the repository (In this github *LabRemo* or *laboratorio_remo_remasterizado*) has the repository and venv configuration

* *%DIR%/labremoto*

This is the principal work directory

* *%DIR%/labremoto/files*

This directory is for files for use in the project (.csv, .db, etc...)
>db_develop.db and topics.csv  

* *%DIR%/labremoto/ros_ws/*

In this directory is the package creation, is used the command: `colcon build` in each change for a new package compilation

* *%DIR%/labremoto/ros_ws/src/pnodos/pnodos*

In this file is our nodes scripts in python (_actions, supervisor, etc_)

* *%DIR%/labremoto/ros_ws/src/pnodos/launch*

In this directory is the launch files to use the command: `ros2 run pnodos *.launch.py` and execute many nodes (_Execute each command in one terminal_)

    ~~~
    ros2 launch pnodos nodos_log.launch.py
    ros2 launch pnodos nodos_inicio.launch.py
    ~~~

* *%DIR%/labremoto/ros_ws/src/pvariable*

In this directory is the enviroment configuration (_actions, messages, etc_)

* *%DIR%/labremoto/ros_ws_src/pnodos/pnodos/parent_class*

In this directory there are the main class files to use as a module

* *%DIR%/labremoto/ros_ws_src/pnodos/pnodos/try*

Old files or testing files. They are now deprecated

### Initial configuration

You need *initial configurations* for this project:

- Install ROS 2 Humble _base_

`https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html`

- Install Colcon for `Colcon Build`

`https://colcon.readthedocs.io/en/released/user/installation.html`

- Code for ROS2 (On each new terminal)

`source /opt/ros/humble/setup.bash`

`source /laboratorio_remo_remasterizado/labremoto/ros_ws/install/setup.bash`
> Example with my own path

_Add this commands to ~/.bashrc (Autoexecution in new terminal)_

- Code for use _nodefather_ as a module (_Maybe this command is not necessary now_)

`export PYTHONPATH=$PYTHONPATH:/laboratorio_remo_remasterizado/labremoto/ros_ws/src/pnodos/pnodos`
> Example with my own path

_Add this command to ~/.bashrc (Autoexecution in new terminal)_

    ~~~
    source /laboratorio_remo_remasterizado/labremoto/ros_ws/install/setup.bash
    ~~~

- Colcon Build: Package and creation (**_Just in a new project_**)

With the command: `ros2 pkg create --build-type ament_python pnodos` create the package to work
>In this project the package is named: _pnodos_

Also you should create package for variables with the same command: `ros2 pkg create --build-type ament_cmake pvariables`
>In this project the variables package is named: _pvariables_ 

In the first time, execute this command: 
`colcon build`

* _laboratorio_remo_remasterizado/labremoto/ros_ws/src/pnodos_

In this directory should be **modified** the files **_package.xml_** and **_setup.py_**

**Add the code (In _package.xml_):** 

~~~
<exec_depend>ros2launch</exec_depend>
<exec_depend>rclpy</exec_depend>
<exec_depend>std_msgs</exec_depend>
    <depend>rosidl_default_generators</depend>
 <depend>rosidl_default_runtime</depend>
 <member_of_group>rosidl_interface_packages</member_of_group>
<exec_depend>pvariables</exec_depend>
~~~

>Add **before** the lines:

~~~
<export>
    <build_type>ament_python</build_type>
  </export>
</package>
~~~

**Add the code (In _setup.py_)**

~~~
from glob import glob
import os
~~~

>Add **before** the line:

`package_name = 'pnodos'`

In the **same** file **add:**

~~~
entry_points={
        'console_scripts': [
            'publisher = pnodos.publisher:main',
            'subscriber = pnodos.subscriber:main',
            'supervisor = pnodos.supervisor:main'
        ],
    },
~~~

>Add **after** the line: `tests_require=['pytest']`

This lines for execute the nodes with just their names:

For example: `ros2 run pnodos supervisor`

In the **same** file **add:**
`(os.path.join('share', package_name), glob('launch/*.launch.py'))`

>Add in data_files[]:

~~~
data_files=[
    ('share/ament_index/resource_index/packages',
        ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']), 
    (os.path.join('share', package_name), glob('launch/*.launch.py')),
],
~~~

* _laboratorio_remo_remasterizado/labremoto/ros_ws/src/pvariables_

In this directory should be **modified** the files **_package.xml_** and **CMakeLists.txt**

**Add the code (In _package.xml_):**

~~~
<depend>geometry_msgs</depend>
<depend>ros2launch</depend>
<depend>rosidl_default_generators</depend>
<depend>rosidl_default_runtime</depend>
<member_of_group>rosidl_interface_packages</member_of_group>
<test_depend>ament_lint_auto</test_depend>
<test_depend>ament_lint_common</test_depend>
~~~

>Add **before** the lines:
~~~
  <export>
    <build_type>ament_cmake</build_type>
  </export>
</package>
~~~

**Add the code (In _CMakeLists.txt_):**

~~~
find_package(rosidl_default_generators REQUIRED)

find_package(geometry_msgs REQUIRED)

set(msg_files
"msg/nombre.msg"
)

set(srv_files
"srv/nombre.srv"
)

set(action_files
"action/nombre.action"
)
~~~

>Add **before** the lines:

~~~
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
~~~


* ### Publisher (For test) / Subscriber (For test) / Supervisor

In this initial version, in the directory: **_laboratorio_remo_remasterizado/labremoto/ros_ws/src/pnodos/pnodos/_**

There are the files: publisher.py, subscriber.py and supervisor.py

These files are sons of the Class _NodeFather_ in _nodefather.py_ (In the same directory).

The **publisher** node has a counter and increse it each 0.5 seconds and publish the counter in the topic (_information_input_)

The **subscriber** has a subscription to the same topic (_information_input_)

These nodes also have the method **_self.initialization_notice()_** from *_NodeFather_*. With this method, both publish in the topic (_information_nodes_) to notice their initialization to the **supervisor** node.

For the topic, all nodes use the method **_self.get_code_tema()_** from *_NodeFather_*. With this method, and using the file **_topics.csv_** 
>(In the directory files)

In this file, the structure with topic and code is generated a code for each topic using **_random.randint_** from **_numpy_**. Each code has ten digits.

The method **_self.get_code_tema()_** search the code for the topic used and the nodes work with this code 

>(Add the prefix "topic_" to each code because ros does not accept topics with only numbers).

* ### File nodos_inicio.launch.py

With this file we can execute the code: `ros2 launch pnodos nodos_inicio.launch.py` and execute the _subscriber_ and _publisher_ nodes with one command.

>Supervisor node did not include (Should be execute in other terminal)

~~~
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package = 'pnodos',
                executable = 'subscriber',
                output = 'screen'
            ),
            Node(
                package = 'pnodos',
                executable = 'publisher',
                output = 'screen'
            )
        ]
    )
~~~

## Version 0.1 | Firsts steps

In this commit the changes are: 

* ### File nodefather.py

    - Create the class **_NodeConn_**. In this class there are two methods:
        * **_self.connection_**

            To connect to the database (In the future with an API)
        * **_self.insert_log_initialization_**

            Use the method _self.connection_ to connect and try insert on the database the information in the message using the sentence: `INSERT INTO log_init (node_name, node_topic, node_datetime) VALUES (?, ?, ?);`

            Also to use in the future with an API.

    - Modify the class **_NodeFather_**:
        * **_self.get_code_tema_**

            Delete some comments
        * **_self.initialization_notice_**

            Modify the line: `msg.data = f"Node {self.get_name()} Initialized//{self.get_name()}, {self.topic_code}, {datetime.now()}"`
            With this, the node send the information to print in the terminal (First part delimited by '//') and the information to save on the database (Second part selimited by '//') 

            In this second part: node_name, topic_code and datetime.

* ### Node databaser.py

    - This node is a son from **_NodeFather_** and **_NodeConn_**.

    - Has a subscription to the _database_nodes_ topic (The same topic which the publish in supervisor node)

    - Has the method **_listener_callback_**
        * Message to tuple
            With the line: `tuple(str(msg.data).split(','))` convert from the string information from the _database_nodes_ topic to tuple for save in database.
        * Save in database
            Use the method from **_NodeConn_** `result = self.insert_log_initialization(data_db)`

            If the result is OK, print in terminal.
            If there is an error, print in terminal the error.

* ### Node supervisor.py

    - Create a publisher in the _database_nodes_ topic.
        
        To publish the information from the nodes and the **_databaser_** node use this information to save it in the database.

    - Edit the listener_callback function:

        Using `NodeFather.listener_callback(self, msg, info_msg)` for continue with the original functionality (Print in the terminal the information from the nodes) and add `self.publisher_.publish(msg)` for publish the information in the  _database_nodes_ topic.

        With `msg.data.split('//')` to separate the message in two parts (The first part to the original functionality and the second part for publish)

* ### File nodos_log.launch.py

With this file we can execute the _supervisor_ and then 2 seconds execute _databaser_ node.

~~~
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package = 'pnodos',
                executable = 'supervisor',
                output = 'screen'
            ),
            TimerAction(
                period = 2.0,  # Espera 2 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'databaser',
                        output = 'screen'
                    )
                ]
            )
        ]
    )

~~~
>Use the delay timer because the databaser also publish in the supervisor in the _nodes_information_ topic.


* ### File nodos_inicio.launch.py

Add the same functionality (delay) with 2.5 seconds between _subscriber_ and _publisher_ nodes.

~~~
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package = 'pnodos',
                executable = 'subscriber',
                output = 'screen'
            ),
            TimerAction(
                period = 2.5,  # Espera 2.5 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'publisher',
                        output = 'screen'
                    )
                ]
            )
        ]
    )
~~~

* ### File database_cr.py
To create and test the **database** created with sqlite

* ### File db_develop.db

File with the **database** created with sqlite

* ### File topics.csv

Add the topic: _database_nodes_ and the code for this new topic.

* ### File setup.py

In this file add the line in the _entry_points_: `'databaser = pnodos.databaser:main'`.

* ###  File publisher.py

Delete some comments

* ### File README.md

Add all the initial configurations, the directory structure, the files to modify and the to _Version 0_ and _Version 0.1_ code in the nodes. 

## Version 0.2 | Begin the code

## Version 0.2.1 | Supervisor and Auditor nodes

In this commit the changes are:

* ### Message Auditor.msg and Operation.msg

    In the directory _pvariables/msg_ create the files **_Auditor.msg_** and **_Operation.msg_**. This are the custom messages to use in the topics nodes

    - Auditor.msg

        ~~~
        int64 idnode
        string namenode
        string typetransaction
        string datetransaction
        string iduser
        string logprocess
        ~~~

    - Operation.msg

        ~~~
        string nameoperation
        string descoperation	
        string statusoperation	
        string dateoperation
        string topicoperation
        ~~~

* ### File CMakeLists.txt

    Add the next lines before `if(BUILD_TESTING)`:

    ~~~
    set(msg_files
    "msg/Operation.msg"
    "msg/Auditor.msg"
    )

    rosidl_generate_interfaces(${PROJECT_NAME}
    ${msg_files}
    #${srv_files} -- comment
    #${action_files} -- comment
    DEPENDENCIES geometry_msgs
    DEPENDENCIES builtin_interfaces
    )
    ~~~

    With these lines, we can use the custom messages.

* ### File nodefather.py

    - Import the custom messages:

    ~~~
    from pvariables.msg import Operation, Auditor
    ~~~

    - Modify the class **_NodeConn_**
        * Modify the **_init_** method class. Add a dictionary for sentences in sql to connect database. With this dictionary we have access to any sentence with a key word from the message type of topics.

        ~~~
        self.diction_db = {
                "supervisor" : """INSERT INTO SUPERVISOROPERACIONES( nameoperacion, DescOperacion, EstatusOperacion, FechaOperacion, TopicOperacion) VALUES (?, ?, ?, ?, ?);""",
                "auditor" : """INSERT INTO TRANSACCIONESAUDITOR (IdNode, NameNode, TipoTransaccion, FechaTransaccion, IdUser, LogProceso) VALUES (?, ?, ?, ?, ?, ?);"""
            }
        ~~~

        * Modify the method class **_insert_log_db_**: 
        
            - Change the variable name to _tuple_db_ and add the _sentence_ parameter

            ~~~
            def insert_log_db(self, tuple_db, sentence):
            ~~~

            - Add the line in the _try_ clause to search the sentence in the dictionary using the key word _sentence_ from the parameters

            ~~~
            try:
                sentence_db = self.diction_db.get(f"{sentence}")
                ...
            ~~~

            - Add the lines to _finally_ clause from the _try_ to close the database connection

            ~~~
            finally:
                conn.commit()
                cur.close()
                ...
            ~~~
    - Modify the class **_NodeFather_**

        * Modify the method class **_get_code_tema_**:

            - Add a _try_ clause to the error codes from the _csv_ file:

            ~~~
            try:
                df = pd.read_csv(path)
                filtered_df = df[df['topic'] == topic]

                if filtered_df.empty:
                    raise ValueError(f"Topic '{topic}' not found.")
                topic_code = 'topic_' + str(filtered_df.iloc[0]['code_topic'])
                return topic_code
            ~~~

            - Add the _except_ clause, **_maybe here add a publisher to console topic_**

            ~~~
            except ValueError as err:
                print(err)
            ~~~

        * Modify the method class **_initialization_notice_**

            - Using the **_Operation_** message create a message to publish in the  _top_supervisor_operations_ topic.

            ~~~
            msg = Operation()
            msg.nameoperation =  "Start Node"
            msg.descoperation = f"{self.get_name()}"
            msg.statusoperation = "Started"
            msg.dateoperation = f"{datetime.now()}"
            msg.topicoperation = f"{self.topic_code}"

            topic = self.get_code_tema('top_supervisor_operations')
            self.create_publisher(Operation, topic, 10).publish(msg)
            ~~~

        * Create the class method **_auditor_msg_**: 

            - Using the _Auditor.msg_ message parameters and returning the message to be used. 

            ~~~
            def auditor_msg(self, logprocess="", idnote=0, iduser="", typetransaction=""):
                msg = Auditor()
                msg.namenode = self.get_name()
                msg.datetransaction = f"{datetime.now()}"
                msg.logprocess = logprocess
                msg.idnode = idnote
                msg.typetransaction = typetransaction
                msg.iduser = iduser
                return msg
            ~~~
        * Modify the class method **_listener_callback_**, change msg.data to print just msg

            ~~~
            self.get_logger().info(f"{info_msg}: {msg}")
            ~~~

    * ### Node supervisor.py (modify)

        - Import the custom messages: Operation `from pvariables.msg import Operation`

        - Change the topic in the _nodefather_ initialization:
        `NodeFather.__init__(self,'top_supervisor_operations')`

        - Modify the subscription to use the custom messages _Operation_ in the topic 
        `self.subscription_ = self.create_subscription(Operation, self.topic_code, self.listener_callback, 10)`

        - Modify the publisher to the database, change the **_db_supervisor_** topic to and use the custom messages _Operation_:
        `self.publisher_ = self.create_publisher(Operation, self.get_code_tema('db_supervisor'), 10)`
        
        _The code modified together:_

        ~~~
        NodeFather.__init__(self,'top_supervisor_operations')
    
        self.subscription_ = self.create_subscription(Operation, self.topic_code, self.listener_callback, 10)
        self.subscription_
        
        self.publisher_ = self.create_publisher(Operation, self.get_code_tema('db_supervisor'), 10)
        ~~~ 

    * ### Node databaser.py (modify)

        - Import the **_Auditor_** and **_Operation_** custom messages: `from pvariables.msg import Auditor, Operation`

        - Change the topic initialized in the nodefather: `NodeFather.__init__(self, "db_supervisor")`

        - Subscription to the **_db_supervisor_** topic, using the **_Operation_** message.
        `self.subscription_ = self.create_subscription(Operation,self.topic_code,self.listener_callback,10)`

        - Subscription to the **_sb_auditor_** topic, using the **_Auditor_** message.
        `self.subscription_auditor_ = self.create_subscription(Auditor,self.get_code_tema("db_auditor"),self.listener_callback,10)`

        - Create a _dictionary_ to save the _keyword_ used in the database according the kind of messages:
            ~~~
            self.diction_msg_type = {
                "<class 'pvariables.msg._auditor.Auditor'>" : "auditor",
                "<class 'pvariables.msg._operation.Operation'>" : "supervisor"
            }
            ~~~

        - Create **_convert_msg_** method function. 
        
            * In this function according the _type_ of message (for now just Operation and Auditor messages) search the keyword: 
            `msg_type = self.diction_msg_type.get(f"{type(msg)}")`
                
            * Convert the message data to tuple (**_THIS FUNCTIONALITY SHOULD BE BETTER AND FOUND A TUPLE CONVERT MODE, EFFICIENT AND FASTER TO CODE_**)
            Now has been used the _if_ sentence: `if msg_type == "auditor":` but, this is not efficient to write code.

            * Return the data in a tuple and the keyword
            `return tuple_db, msg_type`

        - Modify the **_listener_callback_**

            * Use the **_convert_msg_** function: `tuple_db, sentence = self.convert_msg(msg)`

            * This line (From class father, to send data to database)just change the variable name to _tuple_db_: `result = self.insert_log_db(tuple_db, sentence)`

        The code together:

        ~~~
        def __init__ (self):
            ...
            Node.__init__(self,'databaser_logger')
            NodeFather.__init__(self, "db_supervisor")
            ...
        
            self.subscription_ = self.create_subscription(Operation,self.topic_code,self.listener_callback,10)

            self.subscription_auditor_ = self.create_subscription(Auditor,self.get_code_tema("db_auditor"),self.listener_callback,10) 

            self.diction_msg_type = {
                "<class 'pvariables.msg._auditor.Auditor'>" : "auditor",
                "<class 'pvariables.msg._operation.Operation'>" : "supervisor"
            }
            ...
        
        def listener_callback(self, msg):
            tuple_db, sentence = self.convert_msg(msg)
            result = self.insert_log_db(tuple_db, sentence)
            ...
        
        def convert_msg(self,msg):
            msg_type = self.diction_msg_type.get(f"{type(msg)}")
            if msg_type == "auditor":
            ....
            return tuple_db, msg_type
        ~~~

    * ### Node auditor.py (create)
        - Use the _nodefather_ structure and import the Auditor message: `from pvariables.msg import Auditor`

        - Initialize the class fathers with node name **_auditor_transactions_** and use the **_top_auditor_transactions_** topic.

            ~~~
            Node.__init__(self,'auditor_transactions')
            NodeFather.__init__(self,'top_auditor_transactions')
            ~~~

        - Create a _subscription_ to **_top_auditor_transactions_** topic.

            ~~~
            self.subscription_ = self.create_subscription(Auditor, self.topic_code, self.listener_callback, 10)
            ~~~

        - Create a _publisher_ to send the data to **_databaser_** node using the _Auditor_ message through the **_db_auditor_** topic.

            ~~~
            self.publisher_ = self.create_publisher(Auditor, self.get_code_tema('db_auditor'), 10)
            ~~~
        - In the _listener_callback_ method print on console the data and send to **_databaser_**:

            ~~~
            msg_op = f"{msg.namenode} {msg.typetransaction}"
            self.publisher_.publish(msg)
            ~~~

    * ### Node subscriber.py (modify)

        Now this node (and the _publisher_ node) will be used to test and practice codes. In this version is used to publish in the **_supervisAuditoror_** and **_auditor_** nodes to test the database and topic functionality.

        - Import the message: `from pvariables.msg import Auditor`. The Operation message was not imported because it is used in the nodefather class and has been imported in that file.

            ~~~
            # * Prueba para saber el type de message
            #self.msg = Auditor()
            #self.get_logger().info(f"Tipo: {type(self.msg)}")

            # * Prueba para la función de clase padre "auditor_msg"
            self.auditor_test()
        
            def auditor_test(self):
                topic = self.get_code_tema('top_auditor_transactions')
                self.create_publisher(Auditor, topic, 10).publish(self.auditor_msg("Logprocess"))
            ~~~
    

    * ### File nodos_log.launch.py
        Add the **_auditor_** node to the _launcher_ before the **_databaser_** node and after the **_supervisor_** node and modify the timer period to 3 seconds.

        ~~~
        TimerAction(
            period = 3.0,
            actions = [
                Node(
                    package = 'pnodos',
                    executable = 'auditor',
                    output = 'screen'
                )
            ]
        ),
        TimerAction(
            period = 3.0,
            ...
        )
        ~~~

    * ### File topics.csv

    Add the topics: **_top_supervisor_operations_**, **_top_auditor_transactions_**, **_db_supervisor_**, **_db_auditor_** and the codes for these new topics.

    * ### File database_cr.py

        - Add the code lines to create tables for save the data from _Auditor_ and _Operations_ messages.

        - Add the commit method in conn object.

        - Also add test queries to the db, these lines are commented.
        ~~~
        cur.execute("CREATE TABLE IF NOT EXISTS SUPERVISOROPERACIONES(nameoperacion text, DescOperacion text, EstatusOperacion text, FechaOperacion text, TopicOperacion text)")
        cur.execute("CREATE TABLE IF NOT EXISTS TRANSACCIONESAUDITOR(IdNode integer, NameNode text, TipoTransaccion text, FechaTransaccion text, IdUser text, LogProceso text)")

        tables = cur.execute("SELECT * FROM sqlite_master WHERE type = 'table';")
        for table in tables:
            print(table)

        conn.commit()
        ~~~

    * ### File .gitignore

    Add the files: `*.db *.pyc`

    * ### File setup.py

    Add the new node to console scripts: `'auditor = pnodos.auditor:main'`

    * ### File README.md

    Add the _version_ code **0.2** and the _sub-version_ **0.2.1**

* ## Version 0.2.2 | administrator and exit_logger nodes
    * ### File nodefather.py
        - Adding a new sentence to diction_db from the NodeConn class:

            ~~~
            "admin" : """ SELECT * FROM CONTRATOS WHERE IdContrato = ?"""
            ~~~
        - Create _**publisher_consoler**_, a new method in **_NodeFather_** class
            * With this function the node has not send the information to the **_top_console_** topic:

                ~~~
                msg_consoler_ = LogExit()
                #Creando mensaje de consola con los datos pasados en la función
                # * Informe general del tipo de mensaje
                msg_consoler_.logexit = str(info_msg)
                # * Status (Más detalles del mensaje)
                msg_consoler_.status = str(msg)
                self.create_publisher(LogExit, self.get_code_tema('top_console'), 10).publish(msg_consoler_)
                ~~~
        - Create the **_request_info_db_** method in **_NodeConn_**
            This function is simillar to the **__** method to connect DB and execute the query, just adding the auditor verifications:

            Both functions should be better, can be refactorizated because some of the code is repeated.

            In this function, also **_needs to create the verification_** conditional (True != True)
            ~~~
            def request_info_db(self, sentence, conditional_id):
            if self.mode_dev:
                conn,cur = self.connection()
                if conn is not None:
                    msg = ('Transaction Accepted')
                    try:
                        #Busca la sentencia correspondiente en el diccionario
                        sentence_db = self.diction_db.get(f"{sentence}")
                        #Ejecuta la sentencia con los datos de la tupla
                        # ! Falta desarrollar las condiciones para que sea una transacción aceptada
                        # TODO Hacer la función de verificación de contratos  
                        msg_auditor = NodeFather.auditor_msg()
                        msg_auditor.logprocess = "Transaccion aceptada"
                        n_contracts = len(cur.execute(sentence_db, conditional_id))
                        if n_contracts  < 1:
                            msg = ('Transaction Error', 'Transaction not found.')    
                        elif True != True:
                            msg = ('Transaction Error', 'Transaction Rejected.')
                    except(sqlite3.Error):
                        #Regresa el mensaje en caso de error
                        msg = ('Database Error', 'Database error, try again.')
                    finally:
                        #Al final, cierra el cursor y la conexión
                        conn.commit()
                        cur.close()
                        conn.close()
                        return msg
            ~~~
        - Change the function _listener_callback_ (**deprecated**) to **_publisher_consoler_**
            With this function all message to print in the console are send to the node **_exit_logger_** on **_top_console_** topic using the **_LogExit_** message.

            ~~~
            msg_consoler_ = LogExit()
            msg_consoler_.logexit = str(info_msg)
            msg_consoler_.status = str(msg)
            self.create_publisher(LogExit, self.get_code_tema('top_console'), 10).publish(msg_consoler_)
            ~~~


    * ### Node administrator.py (create)
        - This node is a children from _Node, NodeFather_ and _NodeConn_

        - This node has a subscription to **_top_transactions_** topic.

        - This node has three publishers:

            * **_publisher_auditor__** for publish in the **_top_auditor_transactions_** topic.

            * **_publisher_admintrans__** for publish in the **_top_transactions_accepted_** topic.

            * **_publisher_console__** in the **_top_console_** topic.

        - **_listener_callback_** method function: Is the callback function for receive the **_Contract_** messages from the **_top_transactions_** topic.

            * Use the **_request_info_db_** from the _NodeConn_ class:

            ~~~
            result = NodeConn.request_info_db('admin',msg.idcontract)
            ~~~

            * Compare the result retorned from the method: If there are two (>1) message from the result, is an error.

                ~~~
                if len(result)>1:
                ~~~

                - If there is some error, create a **_LogExit_** message for publish in the **_top_console_** topic and print on console.

                    ~~~
                    logprocess = result[1]
                    msg_log =  LogExit()
                    msg_log.logexit = result[1]
                    self.publisher_console_.publish(msg_log)
                    ~~~
                - If there are not errors, publish a empty message with the **_publisher_admintrans_** in the **_top_transactions_accepted_** topic.

                    ~~~
                    logprocess = "Transaccion Accepted"
                    if len(result)>1:
                    ...
                    else:
                        self.publisher_admintrans_.publish()
                    ~~~
                
            * Create an _Auditor_ message with the _logprocess_ result(Error or success) and publish it with **_publisher_auditor__** in the **_top_auditor_transactions_** topic.

            ~~~
            msg_auditor = self.auditor_msg(logprocess)
            self.publisher_auditor_.publish(msg_auditor)
            ~~~

    * ### Node exit_logger.py (create)
        - This is a children from _Node and NodeFather_

        - This node has a subscription to **_top_console_** topic. With this subscription receive messages from all nodes for print on console.

        - In the _listener_callback_ method just print on console the message:

            ~~~
            self.get_logger().info(f"{msg.logexit}: {msg.status}")
            ~~~


    * ### Node supervisor.py, auditor.py, databaser.py, auditor.py (modify)
        Modify the _listener_callback_, to use the publisher_consoler method class (**Now the listener callback function does not exist**) in the next line:

        ~~~
        NodeFather.publisher_consoler(self, msg_op, info_msg)
        ~~~

        - Node publisher.py
        
            ~~~
            NodeFather.publisher_consoler(self,msg,'Published')
            ~~~
        - Node databaser.py

            ~~~
            if result == 'Success':
                NodeFather.publisher_consoler(self,tuple_db,'Information upload to database')
            else:
                msg = result[0]
                NodeFather.publisher_consoler(self, msg, result[1])
            ~~~
    * ### Node subscriber.py
        _Change the subscription callback name just to **_self.callback_**_

    * ### File nodos_log.launch.py
        We have added the administrator and exit_logger nodes to launcher first the exit_logger and at finally the administrator node. In the firsts node (exit_logger then supervisor) there is not a time diley.

    * ### Message Contract.msg

        _Using in the administrator node in the **top_transactions** topic._

        ~~~
        int64 idcontract
        string namecontract
        string typecontract
        string desccontract
        string specificationcontract
        ~~~

    * ### Message LogExit.msg
        _Using in the node exit_logger in the  **top_console** topic._

        ~~~
        string logexit
        string status
        ~~~

    * ### Message TransGlobal
        _Using in the administrator node in the  **top_transactions_accepted** topic._

        ~~~
        string result
        string status
        string name_node
        string date
        string folio
        ~~~
    * ### File topics.csv
        Adding the new topics names:

        ~~~
        top_transactions
        top_transactions_accepted
        top_console
        ~~~

    * ### File setup.py
        Add the new nodes to console script:

        ~~~
        'administrator = pnodos.administrator:main',
        'exit_logger = pnodos.exit_logger:main',
        ~~~

    * ### File CMakeLists
        - Add the new messages:

        ~~~
        "msg/Contract.msg"
        "msg/LogExit.msg"
        "msg/TransGlobal.msg"
        ~~~

    * ### File README.md
        Add the _sub-version_ **0.2.2** and the commands to initialize the nodes

* ## Version 0.2.3 | input_transactioner, transactioner nodes and message attributes (snake_case)

    * ### Node administrator (modify)

        - Change name message attributes (To use _snake_case_)

        ~~~
        #Before
        msg_log.logexit = result[1]

        #After
        msg_log.log_exit = result[1]
        ~~~
    * ### Node databaser (modify)

        - Modify the attribute **_diction_msg_type_** to add the attributes for each message

            ~~~
            #Before
            self.diction_msg_type = {
                "<class 'pvariables.msg._auditor.Auditor'>" : "auditor",
                "<class 'pvariables.msg._operation.Operation'>" : "supervisor"
            }
            #After
            self.diction_msg_type = {
                "<class 'pvariables.msg._auditor.Auditor'>" : ["auditor", ["id_node", "name_node", "type_transaction", "date_transaction", "id_user", "log_process"]],
                "<class 'pvariables.msg._operation.Operation'>" : ["supervisor", ["name_operation", "desc_operation", "status_operation", "date_operation", "topic_operation"]]
            }
            ~~~
        - Modify the **_convert_msg_** method to convert message attributes to a tuple. Before were if and else-if (No Efficient)

            ~~~
            tuple_db = tuple(getattr(msg,attr) for attr in msg_type[1])
            msg_type = str(msg_type[0])
            ~~~
    
    * ### Node exit_logger (modify)

        - Change name message attributes (To use _snake_case_)

        ~~~
        #Before
        self.get_logger().info(f"{msg.logexit}: {msg.status}")

        #After
        self.get_logger().info(f"{msg.log_exit}: {msg.status}")
        ~~~

    * ### Node supervisor

        - Change name message attributes (To use _snake_case_)

        ~~~
        #Before
        msg_op = f"{msg.nameoperation} {msg.descoperation}"

        #After
        msg_op = f"{msg.name_operation} {msg.desc_operation}"
        ~~~

    * ### File nodefather.py

        - Change name message attributes (To use _snake_case_)

        - Add two news sentences for sql in **_diction_db_**

            ~~~
            "admin" : """ SELECT * FROM CONTRATOS WHERE IdContrato = ?;""",
            "input_transactioner" : """ SELECT * FROM USUARIOS WHERE Id = ?;"""
            ~~~
        
        - Create **_diction_db_errors_** attribute for error messages and their types:

            ~~~
            self.diction_db_errors = {
                "default": ('Database Error', 'Database error, try again.'),
                "admin" : ('Transaction Error', 'Transaction not found.'),
                "admin_condition": ('Transaction Error', 'Transaction Rejected.'),
                "input_transactioner" : ('Transaction Error',"Transaction cannot be processed")
            }
            ~~~
        
        - Modify **_insert_log_db_** method. 

            ~~~
            #Before
            msg = ('Database Error', 'Database error, try again.')

            #After
            msg = self.diction_db_errors.get("default")
            ~~~

        - Modify **_request_info_db_** method to use the attribute **_(# -- TODO: Make the contracts verification function)_**. _Maybe this functionality can be better._

            ~~~
            if n_contracts  < 1:
                msg = self.diction_db_errors.get(f"{sentence_db}") 
                if sentence_db == "admin" and n_contracts>0 and _True != True_:
                    msg = self.diction_db_errors.get(f"{sentence_db}_condition")
            except(sqlite3.Error):
                msg = self.diction_db_errors.get("default")
            ~~~

    * ### Modify messages to rename attributes (Auditor.msg, Contract.msg, LogExit.msg, Operation.msg)
        * #### Auditor.msg
        ~~~
        int64 id_node
        string name_node
        string type_transaction
        string date_transaction
        string id_user
        string log_process
        ~~~

        * #### Contract.msg

        ~~~
        int64 id_contract
        string name_contract
        string type_contract
        string desc_contract
        string specification_contract
        ~~~

        * #### LogExit.msg

        ~~~
        string log_exit
        string status
        ~~~

        * #### Operation.msg

        ~~~
        string name_operation
        string desc_operation	
        string status_operation	
        string date_operation
        string topic_operation
        ~~~

    * ### Message CreateBitStream.msg
     
        - Message used in **_transactioner_** node on **_top_files_bit_** topic.
    ~~~
    string path_vhdl
    string path_constrains
    string path_savefolder
    ~~~

    * ### Message FileHexLoad.msg

        - Message used in **_transactioner_** node on **_top_files_hex_** topic.
    ~~~
    string path_hex
    string status
    ~~~

    * ### Message TransInput.msg

        - Message used in **_input_transactioner_** node on **_top_transactions_input_** topic.

    ~~~
    string type_transaction
    string status
    string id_student
    string id_session
    string description
    ~~~

    * ### Node input_transactioner (create)

        - This node is a children from _NodeFather_ and _NodeConn_.

        - This node has a subscription to **_top_transactions_input_** topic, using **_TransInput_** messages.

        - Also, it has a publisher on **_top_transactions_** using **_Contract_** messages.

        - **_listener_callback_** (from **_top_transactions_input_**): 

            * Use the **_request_info_db_** method from _NodeConn_ class parent.

                ~~~
                result = NodeConn.request_info_db(self, "input_transactioner", msg.id_student)
                ~~~
            
            * If there are error, publish them on **_exit_logger_** node using **_publisher_consoler_** method from _NodeFather_.

            * If there are not errors, and the type of message is charge_hex, (_msg.type_transaction == "charge_hex"_): 

                - Create a **_Contract_** message (Check why it using the 4 id):

                - Publish the message on **_top_transactions_** topic.

                    ~~~
                    msg_contract = Contract()
                    msg_contract.id_contrato = '4'
                    msg_contract.name_contrato = 'charge'
                    msg_contract.type_contrato = 'hex'
                    msg_contract.desc_contrato = msg.description

                    msg_contract.specification_contract
                    self.publisher_contract_(msg_contract)
                    ~~~

                - _Maybe after then create the functionality for .bit files_

    * ### Node transactioner (create)

        - This node has a subscription to **_top_transactions_accepted_** topic, using **_TransGlobal_** message.

        - Also it has two publishers to **_top_files_hex_** and **_top_files_bit_**, using **_FileHexLoad_** and **_CreateBitStream_** messages.

        - **_listener_callback_** (from **_top_transactions_accepted_** topic messages): 

            * Look the **_name_node_** and do a _if.else_

                - ´if msg.name_node == '':´

                    * Create a FileHexLoad message

                    ~~~
                    msg_type.path_hex = file_path
                    ~~~
                
                - Else, the same  functionality using for **_CreateBitStream_** topic.

                    ~~~
                    msg_type.path_bit = file_path
                    ~~~
                
                - Both, publish the message in thier publisher.

    * ### File setup.py

        - Add new nodes

            ~~~
            'transactioner = pnodos.transactioner:main',
            'input_transactioner = pnodos.input_transactioner:main'
            ~~~

    * ### File topics.csv

        - Add new topics:

            ~~~
            id,topic,code_topic,date_time
            0,information_input,7163451764,2024-08-14 16:02:36.838129
            1,information_nodes,9892963079,2024-08-14 16:02:36.838135
            2,database_nodes,6169142929,2024-08-14 16:02:36.838136
            3,top_supervisor_operations,6860113761,2024-08-14 16:02:36.838137
            4,top_auditor_transactions,9064527794,2024-08-14 16:02:36.838137
            5,db_supervisor,9026847638,2024-08-14 16:02:36.838138
            6,db_auditor,9016171828,2024-08-14 16:02:36.838138
            7,top_transactions,5777943664,2024-08-14 16:02:36.838139
            8,top_transactions_input,6342311695,2024-08-14 16:02:36.838139
            9,top_transactions_accepted,4218925679,2024-08-14 16:02:36.838140
            10,top_console,5565330701,2024-08-14 16:02:36.838140
            11,top_files_hex,5066469606,2024-08-14 16:02:36.838141
            12,top_files_bit,6422901178,2024-08-14 16:02:36.838142
            ~~~

    * ### File CMakeLists.txt

        - Add new messages

            ~~~
            "msg/CreateBitStream.msg"
            "msg/FileHexLoad.msg"
            "msg/TransInput.msg"
            ~~~
    
    * ### File README.md

        - Add the Version 0.2.3 | input_transactioner, transactioner nodes and message attributes (snake_case)

* ## Version 0.3 | Starting the actions

* ## Version 0.3.0 | arduino_inf_server, arduino_inf_client, ActionParentServer, ActionParentClient, venv Python

    * ### (NEW) Node _**arduino_inf_client**_ (new)

        - Use the _**ActionParentClient**_ class and the action _**HexCharge.action**_

        - Subscription to _top_files_hex_ topic

        - _**listener_callback()**_: Call the function_callback of their class and give the msg as a parameter

            ~~~
            ActionParentClient.function_callback(self,msg)
            ~~~

    * ### (NEW) Node _**arduino_inf_server**_ (new)

        - Use the _**ActionParentServer**_ class and the action _**HexCharge.action**_

        - Custom exception for the errors:

            * **_DeviceNotFoundError_**

            * **_PortNotFoundError_**

        - **_init()_**: Initialize the server action with the method from class

            ~~~
            ActionParentServer.__init__(self, HexCharge, 'arduino_inf')
            ~~~
        - **_execute_callback_**:

            * try block for **_execute_goal()_** from parent class

            * Search available devices: `devices = json.loads(os.popen("arduino-cli board list --format json").read())`. If there is an error raise the **_DeviceNotFoundError_** exception

            * Search the port from device. If there is an error raise the **_PortNotFoundError_** exception:

                ~~~
                for device in devices['detected_ports']:
                    if 'port' in device and 'address' in device['port'] and ('USB' in device['port']['address'] or 'ACM' in device['port']['address']):
                        # Verifica que exista la propiedad de port y de address. Verifica que el puerto sea el correspondiente para arduinos
                        port = device['port']['address']
                        break
                ~~~
            
            * Save the file path from _goal_handle_: `file_path = goal_handle.request.path_hex`. If not exist raise **_FileNotFoundError_** exception.

            * Execute command with parent class method and the params:

                ~~~
                ActionParentServer.execute_command(self, 'arduino', port, file_path)
                ~~~
            
            * Exception management (for each error type) with the structure:

                ~~~
                except Exception as e:
                self.callback_error(err=0)  # Error genérico adicional
                self.send_feedback("Unexpected error: {e}")
                ~~~
            * Finally (both cases): return the results to action client. `return self.result `    
    * ### File nodefather.py

        - **ActionParentServer** Class

            * ___init__()_: Attributes with the params, to use on differents actions

                ~~~
                self._action_server = ActionServer(self, action_type,action_name,self.execute_callback)
                #Guarda el tipo de acción
                self.action_type = action_type
                self.action_name = action_name
                #Inicializa el Result del tipo de acción
                self.result = self.action_type.Result()
                ~~~

            * **Dictionaries** (commands and errors):

                ~~~
                self.dict_action_server = {
                    'arduino': "avrdude -c arduino -P {port} -b 115200 -p atmega328p -D -U flash:w:{file_path}",
                    'vhdl_to_bit' : '',
                    'charge_bit' : ''
                }
                self.dict_action_server_errors = [
                    'Unexpected error.',
                    'Infrastructure error, microcontroller not found.',
                    'Device port not found.',
                    'File not found.'
                ]
                ~~~
            * **send_feedback()**: Sending the feedback messages to client

            * **execute_goal()**: Receive the goal and init the feedback_msg as attribute

            * **execute_command()**:

                - With a Try block, execute the command saved in the **_dict_action_server_** search the key with the **_command_name_** from params `command_template = self.dict_action_server[command_name]`

                - Format the command with for the params: `command = command_template.format(port=port, file_path=file_path, constrain_path=constrain_path)`

                - Execute the command and read the results: `command_r = os.popen(command).read()`

                - Send the feedback and save the final status for mark a success goal:

                    ~~~
                    self.result.status_final = command_r         
                    self.goal_handle.succeed()
                    ~~~

                - In case of error, call the **_callback_error()_** method

                - Finally (both cases) publish on auditor node: `NodeFather.auditor_msg(self, logprocess=self.result.status_final)`

            * **callback_error()**: Abort the goal and publish the results on console and auditor `self.result.status_final = self.dict_action_server_errors[err]`

        - **ActionParentClient** Class

            * ___init__()_: Attributes with the params, to use on differents actions

                ~~~
                self._action_client = ActionClient(self,action_type, action_name)
                self.action_type = action_type
                ~~~

            * _send_goal()_: Create the goal action, and verify the path from params (Arduino or VHDL)

                - Sending the action to ActionParentServer:

                    ~~~
                    self._action_client.wait_for_server()        
                    self._send_goal_future = self._action_client.send_goal_async(goal_msg)
                    return self._send_goal_future
                    ~~~ 
            
            * _function_callback()_

                - `if msg.path_hex != None:` (arduino) `else` (VHDL)

                - In both cases (With their own params): `future = self.send_goal(msg.path_vhdl, msg.path_constrains)`

                - Wait for the actions results: `rclpy.spin_until_future_complete(self, future)`

                - Publish on console and auditor

            - **Missing** to create the _feedback_callback_ for receive the server feedback.
        
        - **NodeConn** class

            * **_request_info_db()_**:
                
                - Add the _data_ variable for save information from database (Now missing this implementation)

                - Using the _contract_id_ for search the information on database (Missing the verification functionality)

                    ~~~
                    sentence_2 = "SELECT * FROM CONTRATOS WHERE IdContrato = ?;"
                    n_contracts = 0
                    for contract in cur.execute(sentence_db, (conditional_id,)):
                        print(contract)
                        n_contracts = n_contracts +1
                    ~~~

        - **NodeFather** class

            * **_auditor_msg_**: change the _msg_ to _msg_auditor_

    * ### (NEW) Action HexCharge.action

        - This action is used for the action to programm the arduino microcontroller

        - _Params, result, feedback_:


        ~~~
        string path_hex
        ---
        string status_final
        ---
        string status
        ~~~

    * ### Node administrator.py

    - Change the path of DB used for NodeConn: `'/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db'`

    - Delete the publisher_auditor and the publisher_console because they have implemented in the NodeFather

    - Adding the variable _data_ as a returned variable from _NodeConn.request_info_db()_

    ~~~
    result,data = NodeConn.request_info_db(self,'admin',msg.id_contract)
    ~~~

    - Using the _data_ from DB to create a _**TransGlobal**_ message and publish it on the _top_transactions_accepted_

        ~~~
        msg_tran_accepted = TransGlobal()
        msg_tran_accepted.result = data.get('result')
        msg_tran_accepted.status = data.get('status')
        msg_tran_accepted.name_node = data.get('name_node')
        msg_tran_accepted.date = data.get('date')
        msg_tran_accepted.folio = data.get('folio')
        NodeFather.publisher_consoler(self,msg_tran_accepted,'Transaction published')
        self.publisher_admintrans_.publish(msg_tran_accepted)

    * ### Node transactioner.py

        - **listener_callback**

            * Using a test path for arduino (hex file). Should be a database verification...

            ~~~
            file_path = '/home/laboratorio_remo_remasterizado/labremoto/files/build/blink.ino.hex'
            ~~~


    * ### Node input_transactioner.py

        - Add the subscription to _*input_transactioner*_. This topic is used for the **ros bridge** comunication.

            * Now, the topic is just a string because the tests have done on console by command: `ros2 topic pub --once top_transactions_input pvariables/TransInput "{type_transaction : 'ros2', status : 'contract', id_student : 12, id_session : 'session_id1', description : 'Prueba'}"`

        - _**listener_callback**_ method

            * The verification and the conection to DB is commented for the test

            * Change the name attributes in  _**msg_contract**_

    * ### Node auditor.py

        - Change the msg attributes to new names: `msg_op = f"{msg.name_node} {msg.type_transaction}"`
    * ### Node databaser.py

        - Change the database path: `'/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db'`

    * ### File nodos_log.launch.py

        - Add the _**input_transactioner**_ , _**administrator**_ and _**transactioner**_ nodes:

        ~~~
        TimerAction(
            period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
            actions = [
                Node(
                    package = 'pnodos',
                    executable = 'input_transactioner', #1ro en recibir
                    output = 'screen'
                )
            ]
        ),
        TimerAction(
            period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
            actions = [
                Node(
                    package = 'pnodos',
                    executable = 'administrator', #2do en recibir
                    output = 'screen'
                )
            ]
        ),
        TimerAction(
            period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
            actions = [
                Node(
                    package = 'pnodos',
                    executable = 'transactioner', #3ro en recibir y que envia actions
                    output = 'screen'
                )
            ]
        )
        ~~~
    * ### File nodos_inicio.launch.py

        - Change to use the _**arduino_inf_server**_ and _**arduino_inf_client**_ nodes:

        ~~~
        Node(
            package = 'pnodos',
            executable = 'arduino_inf_server',
            output = 'screen'
        ),
        TimerAction(
            period = 2.5,  # Espera 2.5 segundos antes de iniciar el siguiente nodo
            actions = [
                Node(
                    package = 'pnodos',
                    executable = 'arduino_inf_client',
                    output = 'screen'
                )
            ]
        )
        ~~~

    * ### File setup.py

        - Adding the nodes for arduino action
            ~~~
            'arduino_inf_client = pnodos.arduino_inf_client:main',
            'arduino_inf_server = pnodos.arduino_inf_server:main'
            ~~~


    * ### (NEW) File requirements.txt

        - In this file, there is a list of packages and sources with the version to use in the venv

        - For activate the venv use the command: `source bin/activate` in the directory "laboratorio_remo_remasterizado"

    * ### File CMakeLists.txt

        - Adding the action _HexCharge_

        ~~~
        set(action_files
        "action/HexCharge.action"
        )
        ~~~

    * ### File README.md

        - Adding version 0.3.0 and commands to use

* ## Version 0.3.1 | Fixing the requirements.txt, installation and venv

    * ### File requirements.txt

        - Fixing the format for version dependencies

        - Adding more dependencies 
    
    * ### File README

        - Adding instructions and fixing steps to initialize the venv

* ## Version 0.3.2 | Directory Try and modify class name

    * ### Directory _Try_

        - This directory is used to save files for testing or to trying in the system, but the files are not in use now.

        - Modify the nodefather.py file in this directory

    * ### Nodes: _administrator_, _arduino_inf_client_, _arduino_inf_server_, _auditor_, _databaser_, _exit_logger_, _input_transactioner_, _supervisor_ and _transactioner_

        - Some changes minors

        - Change the importation to **_parent_class_**

* ## Version 0.3.3 | Modularization of the parent class

    * ### (NEW) Directory _parent_class_ 

        - In this directory, there are the class python files and the __*__init __.py*__ file to import all classes, replacing the **_nodefather.py_** file
    
    * ### (NEW) File *__init __.py*

        - **_main_function_** (Before in nodefather.py)
            
        - Importing all class files (Now in separate files)

            ~~~
            from .node_father import NodeFather
            from .node_conn import NodeConn
            from .action_parent_server import ActionParentServer
            from .action_parent_client import ActionParentClient
            ~~~

        - Use the abstract class __*__all__*__ to export all class

            ~~~
            __all__ = ['NodeFather','NodeConn','ActionParentServer','ActionParentClient','main_base']
            ~~~

    * ### File __*node_conn.py*__ and __*node_father.py*__: The same class, just changing the imports

        - _Conn_ (imports)

            ~~~
            import sqlite3
            ~~~

        - _Father_ (imports)

            ~~~
            from pvariables.msg import Operation, Auditor, LogExit
            from datetime import datetime
            import pandas as pd
            ~~~
        
    * ### (NEW) File __*action_parent_client.py*__

        - Fixing all structure for a correct functionally

        - *function_callback()*

            * Receive the message and verify if is the arduino or vhdl action

            * Execute the *send_goal()* with the correct params

        - *send_goal()*

            * Start the **_goal_** with the action type

            * Execute the *wait_for_server()* method from *_action_client*

            * Send the async goal and the feedback_callback 
            
                ~~~
                self._send_goal_future = self._action_client.send_goal_async(goal_msg,feedback_callback=self.feedback_callback)
                ~~~
            * Add the done_callback to execute when the goal is finished

                ~~~
                self._send_goal_future.add_done_callback(self.goal_response_callback)
                ~~~

        - *goal_response_callback()*

            * Get the result from future (_result returned from server action_)

            * Verify that the goal was accepted by the server action

            * Get the async result 

                ~~~
                self._get_result_future = goal_handle.get_result_async()
                ~~~

            * Add the done result action to execute when the results had been received

                ~~~
                self._get_result_future.add_done_callback(self.get_result_callback)
                ~~~
        - *get_result_callback()*

            * Get the result

                ~~~
                result = future.result().result.status_final 
                ~~~
            
            * Print the result on console

                ~~~
                NodeFather.publisher_consoler(self,result,'Action result')
                ~~~

            * Publish the result on *auditor*

                ~~~
                NodeFather.auditor_msg(self, logprocess=f"Goal sent from {self.get_name()} and result {result}", typetransaction="Goal Finished")
                ~~~
        - *feedback_callback()*

            * Receive the feedback.status from feedback

            * Print the feedback on console

                ~~~
                #Recibiendo feedback del action_server y publicando en consola
                ~~~
    * ### (NEW) File __*action_parent_server.py*__

        - *execute_goal()*: Save the *goal_handle* and initialize the feedback. Called first by the instance and send feedback

        - *send_feedback()*: Send feedback messages to the client

        - *execute_command()*: Execute the command. When it has been executed, mark  the goal as success and return the result
    
* ## Version 0.3.4 | Improving the code instructions and the organization of folders and files

    * ### File README.md

        - Modify instructions

        - Fixing some errors

        - Adding more comments

* ## Version 0.3.5 | Adding the exceptions, for contracts actions and node_conn to database

    * ### (NEW) File _exceptions.py_: This file is used to save the custom exceptions for the entire system with a unique message for each exception

        - **_Database_** Exceptions: Exceptions for node_conn class: `RowNotFoundError, DataBaseNotConnected, DataNotFoundError`

        - **_Contracts_** Exceptions: Exceptions for contracts and command execution in action_parent_server: `DeviceNotFoundError, PortNotFoundError, ContractNotValidError, CommandExecutionFailedError, FileNotFoundError`

    * ### File *_init__.py*

        - Adding the new classes from exception.py file

    * ### File README.md

        - Adding the v0.3.5
    
* ## Version 0.3.6 | esptool, action and message to use with the esp32

    * ### File **_setup.py_**: Adding the nodes for the action to program the esp32

        ~~~
            'esp32_inf_client = pnodos.esp32_inf_client:main',
            'esp32_inf_server = pnodos.esp32_inf_server:main'
        ~~~

    * ### (NEW) Message **_FileBinLoad_**: This message is used to receive message by the esp32 client

        ~~~
        string path_bin
        string status
        ~~~

    * ### (NEW) Action **_BinCharge.action_**: This action is used by the esp32 microcontroller

        ~~~
        string path_bin
        ---
        string status_final
        ---
        string status
        ~~~

    * ### Action ChargeHex.action -> **_HexCharge.action_**: Just rename the action

    * ### File **_CMakeLists.txt_**: Adding `msg/FileBinLoad.msg` and `action/BinCharge.action`

    * ### File **_topics.csv_**

        - Adding the *top_files_bin* topic and update the topic codes

    * ### File **_requirements.txt_**

        - Add the module _esptool.py_ and update the file: `pip install esptool.py`

    * ### File **_README.md_**

        - Adding the v0.3.6

* ## Version 0.3.7 | Using the custom exceptions, improving the action_parent_server and the action_parent_client

    * ### Launch **_nodos_inicio.launch.py_**: Adding the esp32 action nodes

    * ### Class **_NodeConn_** 

        - Implementing the custom exceptions: `DataBaseNotConnected, RowNotFoundError`

        - Create the *callback_error* method to print the error messages

        - Deleting the errors dictionary

        - Deleting the contract verification (Now on _administrator_)

    * ### Class **_ActionParentServer_**

        - Modify the *execute_command* to replace _os.popen()_ to **_subprocess.check_output(command,shell=True,text=True)_**

            ~~~
            import subprocess
            ~~~

        - Modify the *callback_error* to use the message from exceptions and deleting some printed message duplicates in client

        - Adding the *available_port()* method: To check if the custom name port is available. Return True or False and a False raise a custom exception.

        - Adding the commands to use th esp32 and the raspberry

        - Deleting the errors dictionary

    * ### Class **_ActionParentClient_**
        
        - Deliting the *function_callback* method

        - Adding conditional to use *path_bin* and *path_hex*
    
    * ### Node **_transactioner.py_**

        - Adding a path to _.bin_ file (demo): `#file_path = '/home/laboratorio_remo_remasterizado/labremoto/files/build/blink.ino.with_bootloader.bin'`

        - Adding conditional to use esp32, arduino, vhdl, raspberry, etc...

        - Creating a publisher for the esp32: `self.publisher_esp32_ = self.create_publisher(FileBinLoad, self.get_code_tema('top_files_bin'),10)`

    * ### Node **_input_transactioner.py_**: Some comments

    * ### Node **_administrator.py_**

        - Adding the custom exceptions (database): `ContractNotValidError`
        
        - Change the verification of contracts logic to *listener_callback* method (Before in _NodeConn_)

    * ### Node **_arduino_inf_client.py_**: Adding the arguments to use *send_goal* method

    * ### Node **_arduino_inf_server.py_**: Modify the params of *callback_error* to use the custom exceptions and using the custom name on microcontroller port

    * ### (NEW) Node *__esp32_inf_client.py__*: Imlementing the esp32, using _FileBinLoad_ message and _BinCharge_ action

    * ### (NEW) Node *__esp32_inf_server.py__*: Imlementing the esp32 action server, using the custom exceptions

    * ### File **_README.md_**

        - Adding the v0.3.7

* ## Version 0.3.8 | Customizing the port names

    * ### File **_README.md_**

        - Adding the instructions to modify the _name port_ rules and create custom names (For actions)

        - Adding the v0.3.8
* ## Version 0.3.9 | Raspberry action: rasp_inf_client, rasp_inf_server, rshell

    * ### (NEW) Node Action Client __*rasp_inf_client.py*__

    * ### (NEW) Node Action Server __*rasp_inf_server.py*__

    * ### Node **_administrator.py_**

        - Modify the _data_ variable to execute the raspberry action

    * ### Node **_transactioner.py_**

        - Creating the publisher to publish in raspberry topic: `self.publisher_raspberry_ = self.create_publisher(FilePyLoad, self.get_code_tema('top_files_py'),10)`

        - Modify the *file_path* to use a python script

        - Creating the message to publish in raspberry topic

            ~~~
            ...
            elif msg.name_node == 'raspberry':
                msg_type = FilePyLoad()
                msg_type.path_py = file_path
                type_action = 'Raspberry'
                self.publisher_raspberry_.publish(msg_type)
            ~~~

    * ### Class **_ActionParentClient_**

        - *send_goal* method: adding the *path_py=None* param

        - Modify the conditional sentence to execute the raspberry action

            ~~~
            if path_hex is None and path_bin is None:
                goal_msg.path_py = path_py #!Depende del tipo de archivo
            elif path_bin is None:
                goal_msg.path_hex = path_hex
            else:
                goal_msg.path_bin = path_bin
            ~~~

    * ### Class **_ActionParentServer_**

        - *execute_command* method: Saving the result from execution and send as feedback

            ~~~
            result = subprocess.check_output(command,shell=True,text=True)
            self.send_feedback(f'Command executed successfully: {result}')
            ~~~

    * ### Launch __*nodos_inicio.launch.py*__

        - Adding the new action nodes

    * ### (NEW) Action **_PyCharge.action_**

        ~~~
        string path_py
        ---
        string status_final
        ---
        string status
        ~~~

    * ### (NEW) Message **_FilePyLoad.msg_**

        ~~~
        string path_py
        string status
        ~~~

    * ### (NEW) File __*prueba_rasp.py*__ 

        - To test the file upload to the raspberry
    
    * ### File **_setup.py_** 

        - Adding the new nodes

            ~~~
            'rasp_inf_client = pnodos.rasp_inf_client:main',
            'rasp_inf_server = pnodos.rasp_inf_server:main'
            ~~~

    * ### File **_generate.py_**

        - Improving the code to generate the *topic_codes*

            ~~~
            topics['code_topic'] = random.randint(1000000000, 9999999999, size=len(topics))
            topics['date_time'] = datetime.now()
            ~~~

    * ### File **_topics.csv_**
        
        - Adding the *top_files_py* topic

    * ### File **_CMakeLists.txt_**

        - Adding the message and action to use the raspberry

            ~~~
            "msg/FilePyLoad.msg"
            ...
            "action/PyCharge.action"
            ~~~

    * ### File **_README.md_**

        - Adding the installation and usage instructions for raspberry (Rshell)

        - Adding the v0.3.9

* ## Version 0.4.0 | Starting with the FPGA action (There is not the board, then after try and test the node actions and commands)

    * ### (NEW) Node __*fpga_inf_client.py*__: Just remaining the test in a real board

    * ### (NEW) Node __*fpga_inf_server.py*__

        - 🔴Remaining: Do the test in a real board

        - 🔴Remaining: Create the _script.tcl_ and test it

        - 🔴Remaining: Install all necessary command

    * ### Class **_ActionParentServer_**

        - *devices_vivado()* method: To search (in theory) the vivado devices. It need a _.tcl_ script...


    * ### File **_setup.py_**: Adding the new action nodes

        ~~~
        'fpga_inf_client = pnodos.fpga_inf_client:main',
        'fpga_inf_server = pnodos.fpga_inf_server:main',
        ~~~

    * ### (NEW) Message **_FileBitLoad.msg_**

        ~~~
        string path_bit
        string status
        ~~~

    * ### (NEW) Action **_BitCharge.action_** 

        ~~~
        string path_bit
        ---
        string status_final
        ---
        string status
        ~~~

    * ### File **_CMakeLists.txt_**

        - Adding the `FileBitLoad.msg` and `BitCharge.action`

    * ### File **_README.md_**

        - Adding the installations and remaining tasks.

        - Adding the v0.4.0