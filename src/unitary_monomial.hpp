/*__________________________________________________________________________________________________
 * 
 * 		author: Pedro Guarderas
 * 		email: ajusworkopensource@gmail.com
 * 		date: 04-04-2013
 * 		file: unitary_monomial.hpp
 * 	
 * 	This program is free software; you can redistribute it and/or modify it under the terms of the
 * 	GNU General Public License as published by the Free Software Foundation; either version 2 of the
 * 	License, or (at your option) any later version.
 *__________________________________________________________________________________________________
 */

#ifndef UNITARY_MONOMIAL
#define UNITARY_MONOMIAL

#include <iostream>
#include <map>

/*__________________________________________________________________________________________________
 * Unitary Monomial
 */
class Unitary_Monomial : public std::map< int, int > {
public:
  int degree() const;
  Unitary_Monomial& operator= ( const Unitary_Monomial& x );
};

Unitary_Monomial LCM( const Unitary_Monomial& x, const Unitary_Monomial& y );
Unitary_Monomial operator* ( const Unitary_Monomial& x, const Unitary_Monomial& y );
bool operator| ( const Unitary_Monomial& x, const Unitary_Monomial& y );
Unitary_Monomial operator/ ( const Unitary_Monomial& x, const Unitary_Monomial& y );
std::ostream& operator << ( std::ostream& out, const Unitary_Monomial& x );

#endif // UNITARY_MONOMIAL
