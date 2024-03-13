#!/bin/bash
echo "Inicio del LABORATORIO REMOTO"

source /opt/ros/humble/setup.bash
echo "humble sourced ready"

source /home/trabajo/LabRemo/labremoto_ws/install/setup.sh
echo "labremote sourced ready"

commands=(
"ros2 run py_pubsub supervisor_operaciones"
"ros2 launch py_pubsub partes.launch.py"
"ros2 launch /opt/ros/humble/share/rosbridge_server/launch/rosbridge_websocket_launch.xml"
)
ros2 launch /opt/ros/humble/share/rosbridge_server/launch/rosbridge_websocket_launch.xml & pid1=$!

ros2 run py_pubsub supervisor_operaciones & pid2=$!

ros2 launch py_pubsub partes.launch.py & pid3=$!

wait $pid1
wait $pid2
wait $pid3

#parallel --jobs 3 ::: "${commands[@]}" 

#printf "%s \n"
#"${commands[@]}" | xargs -I {} -P 3 sh -c "{}"

echo "supervisor operaciones execution"
echo "partes de orquestador ready"
echo "rosbridge ready"
echo "OK"

