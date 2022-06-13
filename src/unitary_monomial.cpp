/*__________________________________________________________________________________________________

    autor: Pedro Guarderas
    email: pedro.felipe.guarderas@gmail.com
    date: 04-04-2013
    file: unitary_monomial.cpp
 
  This program is free software; you can redistribute it and/or modify it under the 
  terms of the GNU General Public License as published by the Free Software Foundation; 
  either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#include <algorithm>
#include "unitary_monomial.hpp"

/*__________________________________________________________________________________________________
 *    Unitary Monomial definitions
 */
int Unitary_Monomial::degree() const
{
  int degree = 0;
  std::map< int, int >::const_iterator it;
  
  for( it = this->begin(); it != this->end(); ++it )
  {
    degree += it->second;
  }
  
  return degree;
}

Unitary_Monomial& Unitary_Monomial::operator= ( const Unitary_Monomial& x )
{
  Unitary_Monomial::const_iterator it;
  this->clear();
  
  for( it = x.begin(); it != x.end(); ++it )
  {
    ( *this )[ it->first ] = it->second;
  }
  
  return *this;
}

//__________________________________________________________________________________________________
Unitary_Monomial LCM( const Unitary_Monomial& x, const Unitary_Monomial& y )
{
  Unitary_Monomial r;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int mx = std::max_element( x.begin(), x.end() )->first + 1;
  int my = std::max_element( y.begin(), y.end() )->first + 1;
  int x_f = itx->first;
  int y_f = ity->first;
  
  if( x_f != 0 && y_f != 0 )
  {
    while( itx != x.end() || ity != y.end() )
    {
      if( x_f < y_f )
      {
        r[ x_f ] = itx->second;
        itx++;
        x_f = itx->first;
      }
      else if( x_f > y_f )
      {
        r[ y_f ] = ity->second;
        ity++;
        y_f = ity->first;
      }
      else if( x_f == y_f )
      {
        r[ x_f ] = std::max( itx->second, ity->second );
        itx++;
        ity++;
        x_f = itx->first;
        y_f = ity->first;
      }
      
      if( ity == y.end() )
      {
        y_f = mx;
      }
      else if( itx == x.end() )
      {
        x_f = my;
      }
      
    }
  }
  else if( x_f == 0 && y_f != 0 )
  {
    r = y;
  }
  else if( x_f != 0 && y_f == 0 )
  {
    r = x;
  }
  else if( x_f == 0 && y_f == 0 )
  {
    r[ 0 ] = 0;
  }
  
  return r;
}

Unitary_Monomial operator* ( const Unitary_Monomial& x, const Unitary_Monomial& y )
{
  Unitary_Monomial r;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int mx = std::max_element( x.begin(), x.end() )->first + 1;
  int my = std::max_element( y.begin(), y.end() )->first + 1;
  int x_f = itx->first;
  int y_f = ity->first;
  
  if( x_f != 0 && y_f != 0 )
  {
    while( itx != x.end() || ity != y.end() )
    {
      if( x_f < y_f )
      {
        r[ x_f ] = itx->second;
        itx++;
      }
      else if( x_f > y_f )
      {
        r[ y_f ] = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        r[ x_f ] = itx->second +  ity->second;
        itx++;
        ity++;
      }
      
      if( itx == x.end() && ity != y.end() )
      {
        x_f = my;
        y_f = ity->first;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        x_f = itx->first;
        y_f = mx;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
    }
  }
  else if( x_f != 0 && y_f == 0 )
  {
    r = x;
  }
  else if( x_f == 0 && y_f != 0 )
  {
    r = y;
  }
  else if( x_f == 0 && y_f == 0 )
  {
    r[ 0 ] = 0;
  }
  
  return r;
}

bool operator| ( const Unitary_Monomial& x, const Unitary_Monomial& y )
{
  bool test;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity;
  int x_f = itx->first;
  
  if( x_f != 0 )
  {
    do
    {
      ity = y.find( x_f );
      
      if( ity != y.end() )
      {
        if( ity->second >= itx->second )
        {
          itx++;
          x_f = itx->first;
          
          test = true;
        }
        else
        {
          test = false;
          break;
        }
      }
      else
      {
        test = false;
        break;
      }
      
    }
    while( itx != x.end() );
  }
  else
  {
    test = true;
  }
  
  return test;
}

Unitary_Monomial operator/ ( const Unitary_Monomial& x, const Unitary_Monomial& y )
{
  Unitary_Monomial r;
  int deg;
  
  Unitary_Monomial::const_iterator itx;
  Unitary_Monomial::const_iterator ity = y.begin();
  int y_f = ity->first;
  
  for( itx = x.begin(); itx != x.end(); ++itx )
  {
    r[ itx->first ] = itx->second;
  }
  
  if( y_f != 0 )
  {
    do
    {
      itx = x.find( y_f );
      
      if( ity != y.end() )
      {
        deg = itx->second - ity->second;
        
        if( deg > 0 )
        {
          r[ y_f ] = deg;
          
          ity++;
          y_f = ity->first;
        }
        else if( deg == 0 )
        {
          r.erase( y_f );
          ity++;
          y_f = ity->first;
        }
        else
        {
          r.clear();
          break;
        }
      }
      else
      {
        r.clear();
        break;
      }
      
    }
    while( ity != y.end() );
  }
  
  return r;
}

std::ostream& operator << ( std::ostream& out, const Unitary_Monomial& x )
{
  Unitary_Monomial::const_iterator it;
  
  for( it = x.begin(); it != x.end(); ++it )
  {
    if( it->first != 0 )
    {
      out << "X_" << it->first << "^" << it->second << " ";
    }
  }
  
  return out;
}
