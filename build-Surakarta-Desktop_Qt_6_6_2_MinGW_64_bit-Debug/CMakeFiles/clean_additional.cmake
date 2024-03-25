# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Surakarta_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Surakarta_autogen.dir\\ParseCache.txt"
  "Surakarta_autogen"
  )
endif()
