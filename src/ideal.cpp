/*__________________________________________________________________________________________________

    autor: Pedro Guarderas
    email: ajusworkopensource@gmail.com
    date: 04-04-2013
    file: ideal.cpp
 
  This program is free software; you can redistribute it and/or modify it under the 
  terms of the GNU General Public License as published by the Free Software Foundation; 
  either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#include "ideal.hpp"

template< typename Monomial_Order, typename Ring >
Ideal< Monomial_Order, Ring > Ideal< Monomial_Order, Ring >::LT() const
{
    Ideal< Monomial_Order, Ring > r;
    Polynome< Monomial_Order, Ring > p;
    typename Ideal< Monomial_Order, Ring >::const_iterator it;

    for( it = this->begin(); it != this->end(); ++it )
    {
  r.push_back( it->LT() );
    }

    return r;
}

template< typename Monomial_Order, typename Ring >
std::pair< Polynome< Monomial_Order, Ring >, Polynome< Monomial_Order, Ring > >
operator/ ( const Polynome< Monomial_Order, Ring >& x,
            const Ideal< Monomial_Order, Ring >& I )
{
    bool d;
    Polynome< Monomial_Order, Ring > g, aux;
    Polynome< Monomial_Order, Ring > r = x;
    typename Ideal< Monomial_Order, Ring >::const_iterator it;

    do
    {
  d = false;

  for( it = I.begin(); it != I.end(); ++it )
  {
      d = it->LM() | r.LM();

      if( d )
      {
    aux = ( r.LT() / it->LT() ) * ( *it );
    r = r - aux;
    g = g + aux;
      }
  }
    }
    while( d );

    return std::make_pair( g, r );
}
