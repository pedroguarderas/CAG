#___________________________________________________________________________________________________
# 
#		autor: Pedro Guarderas
#		email: pedro.felipe.guarderas@gmail.com
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
