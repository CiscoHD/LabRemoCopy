#!/bin/bash
echo "Inicio del LABORATORIO REMOTO"

source /opt/ros/humble/setup.bash
echo "humble sourced ready"

source /home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/src/install/setup.sh
echo "labremote sourced ready"


conda activate humble

ros2 launch /opt/ros/humble/share/rosbridge_server/launch/rosbridge_websocket_launch.xml
echo "rosbridge ready"

ros2 launch py_pubsub partes.launch.py
echo "partes de orquestador ready"

echo "OK"

