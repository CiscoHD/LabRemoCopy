#!/bin/bash
nombreworkspace=labremoto
pathworkspace=$(pwd)
patharchivos="$pathworkspace/Archivos/"
nombrepackagescripts=scripts
nombrepackagevariables=variables


source /opt/ros/humble/setup.bash

splitproceso="==============================================="

echo $splitproceso
echo "1 - El package '$nombreworkspace' se instalara en el path '$pathworkspace' "

if [ -d "$pathworkspace/$nombreworkspace/" ]
then
	echo $splitproceso
	echo "2 - Folder existe"
else 
	echo $splitproceso
	echo "2 - Se crea nuevo folder para la biblioteca"
	mkdir -p "$pathworkspace/$nombreworkspace/src"
fi

echo $splitproceso
echo "3 - Run colcon build"
cd "$pathworkspace/$nombreworkspace"
colcon build 

echo $splitproceso
echo "4 - Workspace add al path"clear
source "$pathworkspace/$nombreworkspace/install/local_setup.bash"

echo $splitproceso
echo "5 - Make packages"
cd "$pathworkspace/$nombreworkspace/src"
ros2 pkg create --build-type ament_cmake --license Apache-2.0 $nombrepackagevariables
ros2 pkg create --build-type ament_python --license Apache-2.0 $nombrepackagescripts

echo $splitproceso
echo "6 - Insert files to packages"

if [ -d "$patharchivos" ]
then
	echo "Copy files"
	cp -r "$pathworkspace/Archivos/packages/scripts/launch/" "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts"
	echo "Copied launch"
	cp -r "$pathworkspace/Archivos/packages/scripts/scripts/" "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts"
	echo "Copied scripts"
	cp -r "$pathworkspace/Archivos/packages/variables/action/" "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables"
	echo "Copied action"
	cp -r "$pathworkspace/Archivos/packages/variables/msg/" "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables"
	echo "Copied msg"
	cp -r "$pathworkspace/Archivos/packages/variables/srv/" "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables"
	echo "Copied srv"
	
	
else 
	echo "No exite carpeta de archivos dentro del directorio"
fi


echo $splitproceso
echo "7 - Add lista de scripts to setup.py file"

declare listscripts=$(ls "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/$nombrepackagescripts/")
listscripts=( "${listscripts[@]/"__init__.py"}" )

archivo="$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/setup.py"

mv $archivo "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/old_setup.py"

serch="'console_scripts': ["
serchb="    data_files=["
inputb="(os.path.join('share', package_name), glob('launch/*.launch.py')),"
touch $archivo
echo "creatre file setup.py"

echo "added libraries os and glob"
echo "import os" >> $archivo 
echo "from glob import glob" >> $archivo

while IFS= read -r line

do
	echo "$line" >> $archivo
	if [[ "$line" == *$serchb* ]]; then
		echo "        $inputb" >> $archivo
		echo "added  datafile ${inputb}"
	elif [[ "$line" == *$serch* ]]; then
		for i in ${listscripts[@]}
		do
			echo "                '${i} = ${nombrepackagescripts}.${i}:main',">> $archivo
			echo "added script ${i}"
		done

	fi
done < "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/old_setup.py"

echo $splitproceso
echo "8 - Add lista de dependences to package.xml"


archivo2="$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/package.xml"

mv $archivo2 "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/old_package.xml"

serchc="<license>"
dependences=("  " "<exec_depend>rclpy</exec_depend>" "<exec_depend>std_msgs</exec_depend>" "<exec_depend>my_mas</exec_depend>" "<exec_depend>ros2launch</exec_depend>" "<depend>rosidl_default_generators</depend>" "<depend>rosidl_default_runtime</depend>" "<member_of_group>rosidl_interface_packages</member_of_group>")

touch $archivo2
echo "creatre file packagesxml"

while IFS= read -r line

do
	echo "$line" >> $archivo2
	if [[ "$line" == *$serchc* ]]; then

		for i in ${dependences[@]}
		do
			echo "  ${i}" >> $archivo2
			echo "added dependence ${i}"
		done
	fi
done < "$pathworkspace/$nombreworkspace/src/$nombrepackagescripts/old_package.xml"

echo $splitproceso
echo "9 - Add srv,action,msg to CMKaList "


dependences=('find_package(rosidl_default_generators REQUIRED)' 'find_package(geometry_msgs REQUIRED)')


archivo3="$pathworkspace/$nombreworkspace/src/$nombrepackagevariables/CMakeLists.txt"

mv $archivo3 "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables/old_CMakeLists.txt"

serchd="find_package(ament_cmake "

folders=("action" "msg" "srv")

touch $archivo3
echo "creatre file CMakeLists.txt"

while IFS= read -r line

do
	echo "$line" >> $archivo3
	if [[ "$line" == *$serchd* ]]; then
		for i in ${dependences[@]}
		do
			echo "${i}" >> $archivo3
            echo "added dependence ${i}"
		done
		echo 'rosidl_generate_interfaces(${PROJECT_NAME}' >> $archivo3
		for i in ${folders[@]}
		do
			contenido=$(ls "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables/${i}" )
			for j in ${contenido[@]}
			do
				echo " \"${i}/${j}\"" >> $archivo3
                echo "added file ${i}/${j}"
			done
		done
		echo "  DEPENDENCIES geometry_msgs" >> $archivo3
		echo ")" >> $archivo3

	fi
done < "$pathworkspace/$nombreworkspace/src/$nombrepackagevariables/old_CMakeLists.txt"

echo $splitproceso
echo "11 - colcon build news packages"
cd "$pathworkspace/$nombreworkspace/"
colcon build --packages-select $nombrepackagescripts
colcon build --packages-select $nombrepackagevariables


