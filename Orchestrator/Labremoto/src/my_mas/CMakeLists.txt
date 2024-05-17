cmake_minimum_required(VERSION 3.8)
project(my_mas)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)

set(msg_files
"msg/Operacion.msg"
"msg/BitLoad.msg"
"msg/CreateBitStream.msg"
"msg/Auditor.msg"
"msg/SensorMeasurment.msg"
"msg/FileHexLoad.msg"
"msg/TransGlobal.msg"
"msg/Contrato.msg"
"msg/TransEntrada.msg"
"msg/LogSalida.msg"
  )

set(srv_files
"srv/LoadFiledb.srv"
"srv/LoadFile.srv"
  )
  set(action_files
  "action/Fibonacci.action"
  "action/Cargahex.action"
  "action/CargaBit.action"
  "action/Tranformvhdlbit.action"
  )


rosidl_generate_interfaces(${PROJECT_NAME}
${msg_files}
${srv_files}
${action_files}
  DEPENDENCIES geometry_msgs
)

#ament_export_dependecies(rosidl_default_runtime)

#if(BUILD_TESTING)
#  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
#  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
#  set(ament_cmake_cpplint_FOUND TRUE)
#  ament_lint_auto_find_test_dependencies()
#endif()

ament_package()
