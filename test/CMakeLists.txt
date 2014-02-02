#___________________________________________________________________________________________________
# 
#		autor: Pedro Guarderas
#		email: ajusworkopensource@gmail.com
#		date: 11-05-2013
#		file: CMakeLists.txt
#
#	This program is free software; you can redistribute it and/or modify it under the 
#	terms of the GNU General Public License as published by the Free Software Foundation; 
#	either version 2 of the License, or (at your option) any later version.
#___________________________________________________________________________________________________
#

#___________________________________________________________________________________________________
# Files
set( TEST_SRCS
  main.cpp
  )

# set( TEST_HDRS
#   )

#___________________________________________________________________________________________________
# Build
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ../src
  .
  )

#___________________________________________________________________________________________________
# Adding executable 
add_executable( test ${TEST_SRCS} ${TEST_HDRS} )

target_link_libraries( test cag )

#___________________________________________________________________________________________________
# Install
install( TARGETS test
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/test
  )
