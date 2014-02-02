#___________________________________________________________________________________________________
# Files
set( CAG_SRCS
	unitary_monomial.cpp
	)

set( CAG_HDRS
	ideal.hpp
	polynome.hpp
	unitary_monomial.hpp
	)

#___________________________________________________________________________________________________
# Build
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  .
  )

#___________________________________________________________________________________________________
# Adding cag library
add_library( cag MODULE 
  ${CAG_SRCS}
  ${CAG_HDRS}
  )
  
target_link_libraries( cag )

#___________________________________________________________________________________________________
# Install
install( TARGETS cag
# 	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  )

