# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ex_modelview_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ex_modelview_autogen.dir/ParseCache.txt"
  "ex_modelview_autogen"
  )
endif()
