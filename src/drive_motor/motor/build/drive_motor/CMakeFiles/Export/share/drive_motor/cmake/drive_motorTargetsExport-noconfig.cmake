#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "drive_motor::drive_motor_core" for configuration ""
set_property(TARGET drive_motor::drive_motor_core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(drive_motor::drive_motor_core PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdrive_motor_core.so"
  IMPORTED_SONAME_NOCONFIG "libdrive_motor_core.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS drive_motor::drive_motor_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_drive_motor::drive_motor_core "${_IMPORT_PREFIX}/lib/libdrive_motor_core.so" )

# Import target "drive_motor::drive_motor_node" for configuration ""
set_property(TARGET drive_motor::drive_motor_node APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(drive_motor::drive_motor_node PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/drive_motor/drive_motor_node"
  )

list(APPEND _IMPORT_CHECK_TARGETS drive_motor::drive_motor_node )
list(APPEND _IMPORT_CHECK_FILES_FOR_drive_motor::drive_motor_node "${_IMPORT_PREFIX}/lib/drive_motor/drive_motor_node" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
