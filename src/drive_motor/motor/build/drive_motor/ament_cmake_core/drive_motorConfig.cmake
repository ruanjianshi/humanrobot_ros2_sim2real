# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_drive_motor_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED drive_motor_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(drive_motor_FOUND FALSE)
  elseif(NOT drive_motor_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(drive_motor_FOUND FALSE)
  endif()
  return()
endif()
set(_drive_motor_CONFIG_INCLUDED TRUE)

# output package information
if(NOT drive_motor_FIND_QUIETLY)
  message(STATUS "Found drive_motor: 0.1.0 (${drive_motor_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'drive_motor' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${drive_motor_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(drive_motor_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${drive_motor_DIR}/${_extra}")
endforeach()
