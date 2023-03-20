# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtScrcpy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtScrcpy_autogen.dir/ParseCache.txt"
  "QtScrcpyCore/CMakeFiles/QtScrcpyCore_autogen.dir/AutogenUsed.txt"
  "QtScrcpyCore/CMakeFiles/QtScrcpyCore_autogen.dir/ParseCache.txt"
  "QtScrcpyCore/QtScrcpyCore_autogen"
  "QtScrcpy_autogen"
  )
endif()
