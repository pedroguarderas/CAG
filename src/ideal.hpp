/*__________________________________________________________________________________________________

		autor: Pedro Guarderas
		email: ajusworkopensource@gmail.com
		date: 04-04-2013
		file: ideal.hpp
 
	This program is free software; you can redistribute it and/or modify it under the 
	terms of the GNU General Public License as published by the Free Software Foundation; 
	either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#ifndef IDEAL
#define IDEAL

#include <vector>
#include "polynome.hpp"

/*__________________________________________________________________________________________________
 *	Ideal class
 */
template< typename Monomial_Order = grl_order, typename Ring = float > 
class Ideal : public std::vector< Polynome< Monomial_Order, Ring > > 
{
public:
    Ideal< Monomial_Order, Ring > LT() const;
};

template< typename Monomial_Order, typename Ring >
std::pair< Polynome< Monomial_Order, Ring >, Polynome< Monomial_Order, Ring > >
operator/ ( const Polynome< Monomial_Order, Ring >& x, const Ideal< Monomial_Order, Ring >& I );

#include "ideal.cpp"

#endif // IDEAL
