# prevent multiple inclusion
if(_poco_vendor_CONFIG_INCLUDED)
  return()
endif()
set(_poco_vendor_CONFIG_INCLUDED TRUE)

# output package information
if(NOT poco_vendor_FIND_QUIETLY)
  message(STATUS "Found poco_vendor:  (${poco_vendor_DIR})")
endif()
