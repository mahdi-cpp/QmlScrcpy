# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtScrcpy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtScrcpy_autogen.dir/ParseCache.txt"
  "QtScrcpy_autogen"
  "core/CMakeFiles/core_autogen.dir/AutogenUsed.txt"
  "core/CMakeFiles/core_autogen.dir/ParseCache.txt"
  "core/core_autogen"
  )
endif()
