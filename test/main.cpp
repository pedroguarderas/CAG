/*__________________________________________________________________________________________________

		autor: Pedro Guarderas
		email: pedro.felipe.guarderas@gmail.com
		date: 11-05-2013
		file: main.cpp
 
	This program is free software; you can redistribute it and/or modify it under the 
	terms of the GNU General Public License as published by the Free Software Foundation; 
	either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#include <algorithm>
#include <functional>
#include <map>
#include <iostream>
#include <list>
#include <cmath>
#include <vector>

#include "polynome.hpp"
#include "unitary_monomial.hpp"
//#include "fieldp.hpp"

using namespace std;

template< typename Z = int >
bool test_prime( const Z& n ) {
	bool test = true;
	Z a = Z( 2 );
	
	for ( ; a <= std::sqrt( n ); a++ ) {
		if ( n % a == 0 ) {
			test = false;
			break;
		}
	}
	
	return test;
}

int main( int argc, char* argv[] )
{
	Polynome< grl_order, int > f1, f2, r;
	Unitary_Monomial u, v;
	
	u[1] = 1;
	u[2] = 2;
	f1[ u ] = 2;
	u.clear();
	u[3] = 2;
	f1[ u ] = -1;
	
	v[1] = 2;
	f2[ v ] = 3;
	v.clear();
	v[3] = 1;
	f2[ v ] = -1;
	
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	
	r = f1.LT();
	std::cout << r << std::endl;
	r = f1 * f2;
	std::cout << r << std::endl;
	std::cout << S_polynomial( f1, f2 ) << std::endl;
	
	int p = 101*103;
	std::vector< int > plist;
	
	std::cout << test_prime< int >( p ) << std::endl;
	
	std::cout << "Primes:" << std::endl;
	for( int& x : plist ) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	//   FiniteField< int > Field = FiniteField<int>( 2, 3 );
	
	return 0;
}
