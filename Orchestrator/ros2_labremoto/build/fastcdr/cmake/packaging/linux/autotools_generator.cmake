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

macro(generate_sources_for_autotools)
    set(fastcdr_SOURCES_TMP Cdr.cpp;FastCdr.cpp;FastBuffer.cpp;exceptions/Exception.cpp;exceptions/NotEnoughMemoryException.cpp;exceptions/BadParamException.cpp;FastCdr.rc)
    set(fastcdr_SOURCES_AUTOTOOLS "")
    foreach(fastcdr_SOURCE ${fastcdr_SOURCES_TMP})
        set(fastcdr_SOURCES_AUTOTOOLS "${fastcdr_SOURCES_AUTOTOOLS} ${fastcdr_SOURCE}")
    endforeach()
endmacro()

macro(generate_public_headers_for_autotools)
    set(fastcdr_PUBLIC_HEADERS_DIRECTORIES_TMP /home/ffelix07/Documents/LabRemo/Orchestrator/ros2_labremoto/src/eProsima/Fast-CDR/include)
    set(fastcdr_PUBLIC_HEADERS_AUTOTOOLS "")
    foreach(directory ${fastcdr_PUBLIC_HEADERS_DIRECTORIES_TMP})
        file(GLOB_RECURSE fastcdr_PUBLIC_HEADERS_TMP RELATIVE ${directory} ${directory}/*.h)
        foreach(fastcdr_PUBLIC_HEADER ${fastcdr_PUBLIC_HEADERS_TMP})
            set(fastcdr_PUBLIC_HEADERS_AUTOTOOLS "${fastcdr_PUBLIC_HEADERS_AUTOTOOLS} ${fastcdr_PUBLIC_HEADER}")
        endforeach()
    endforeach()

    set(fastcdr_PUBLIC_HEADERS_FILES_TMP fastcdr/config.h)
    foreach(file ${fastcdr_PUBLIC_HEADERS_FILES_TMP})
        set(fastcdr_PUBLIC_HEADERS_AUTOTOOLS "${fastcdr_PUBLIC_HEADERS_AUTOTOOLS} ${file}")
    endforeach()
endmacro()

