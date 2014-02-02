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

