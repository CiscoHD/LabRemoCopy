# Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(PROJECT_NAME fastrtps)
set(PROJECT_NAME_STYLED FastRTPS)
set(PROJECT_NAME_UPPER FASTRTPS)
set(BUILD_DOCUMENTATION OFF)
set(BUILD_JAVA OFF)
set(PROJECT_VERSION_AUTOTOOLS 1:6:0)

if(${CPACK_GENERATOR} STREQUAL "TGZ" )
    if(${CPACK_TOPLEVEL_TAG} STREQUAL "Linux")
        cmake_policy(SET CMP0012 NEW)

        # Define name of the TGZ file
        set(CPACK_PACKAGE_FILE_NAME eProsima_${PROJECT_NAME_STYLED}-1.6.0-Linux)
        set(CPACK_COMPONENTS_ALL headers sources examples)
        if(BUILD_JAVA)
            set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} java)
        endif()
        if(BUILD_DOCUMENTATION)
            set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} documentation)
        endif()
        set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
        set(CPACK_COMPONENTS_ALL_IN_ONE_PACKAGE ON)


        # Include to prepare Makefiles
        include(/home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/build/fastrtps/cmake/packaging/linux/autotools_generator.cmake) 

        # Prepare Makefile.am for autotools
        configure_file(/home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/src/eProsima/Fast-RTPS/Makefile.am.in /home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/build/fastrtps/autotools/Makefile.am)

        # Prepare src/cpp/Makefile.am for autotools
        generate_sources_for_autotools()
        configure_file(/home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/src/eProsima/Fast-RTPS/src/cpp/Makefile.am.in /home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/build/fastrtps/autotools/src/cpp/Makefile.am)

        # Prepare include/Makefile.am for autotools
        generate_public_headers_for_autotools()
        configure_file(/home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/src/eProsima/Fast-RTPS/include/Makefile.am.in /home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/build/fastrtps/autotools/include/Makefile.am)

        # Define cmake script to copy autotools files.
        set(CPACK_INSTALL_SCRIPT "/home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/build/fastrtps/cmake/packaging/linux/AutotoolsPackaging.cmake")
    endif()
endif()
