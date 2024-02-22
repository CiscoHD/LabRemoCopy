cmake_minimum_required(VERSION 3.8)
project(my_mas)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(rosidl_default_generators REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


set(msg_files
	"msg/SensorMeasurment.msg"
)


rosidl_generate_interfaces( ${PROJECT_NAME}
 ${msg_files}
  DEPENDENCIES builtin_interfaces
 )

ament_export_dependencies(rosidl_default_runtime)
ament_export_include_directories(include)

ament_package()
