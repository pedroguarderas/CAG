/*__________________________________________________________________________________________________

    autor: Pedro Guarderas
    email: ajusworkopensource@gmail.com
    date: 11-05-2010
    file: polynome.cpp
 
  This program is free software; you can redistribute it and/or modify it under the 
  terms of the GNU General Public License as published by the Free Software Foundation; 
  either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/


#include "polynome.hpp"
#include <algorithm>


bool pl_order::equal::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  
  if( x.size() == y.size() )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_iterator itx = x.begin();
    Unitary_Monomial::const_iterator ity = y.begin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = ity->second;
        beta = 0;
        itx++;
      }
      else if( x_f > y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = false;
        break;
      }
      else if( alpha < beta )
      {
        test = false;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.end() && ity != y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.end() || ity != y.end() );
    
    if( eq == x.size() )
    {
      test = true;
    }
  }
  else
  {
    test = false;
  }
  
  return test;
}

bool pl_order::less::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int alpha;
  int beta;
  unsigned int eq = 0;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int x_f = itx->first;
  int y_f = ity->first;
  
  do
  {
    if( x_f < y_f )
    {
      alpha = ity->second;
      beta = 0;
      itx++;
    }
    else if( x_f > y_f )
    {
      alpha = 0;
      beta = ity->second;
      ity++;
    }
    else if( x_f == y_f )
    {
      alpha = itx->second;
      beta = ity->second;
      itx++;
      ity++;
    }
    
    if( alpha > beta )
    {
      test = false;
      break;
    }
    else if( alpha < beta )
    {
      test = true;
      break;
    }
    else if( alpha == beta )
    {
      eq++;
    }
    
    
    if( itx == x.end() && ity != y.end() )
    {
      test = true;
      break;
    }
    else if( itx != x.end() && ity == y.end() )
    {
      test = false;
      break;
    }
    else if( itx != x.end() && ity != y.end() )
    {
      x_f = itx->first;
      y_f = ity->first;
    }
    
  }
  while( itx != x.end() || ity != y.end() );
  
  if( eq == x.size() )
  {
    test = false;
  }
  
  return test;
}

bool pl_order::leq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int alpha;
  int beta;
  unsigned int eq = 0;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int x_f = itx->first;
  int y_f = ity->first;
  
  do
  {
    if( x_f < y_f )
    {
      alpha = ity->second;
      beta = 0;
      itx++;
    }
    else if( x_f > y_f )
    {
      alpha = 0;
      beta = ity->second;
      ity++;
    }
    else if( x_f == y_f )
    {
      alpha = itx->second;
      beta = ity->second;
      itx++;
      ity++;
    }
    
    if( alpha > beta )
    {
      test = false;
      break;
    }
    else if( alpha < beta )
    {
      test = true;
      break;
    }
    else if( alpha == beta )
    {
      eq++;
    }
    
    
    if( itx == x.end() && ity != y.end() )
    {
      test = true;
      break;
    }
    else if( itx != x.end() && ity == y.end() )
    {
      test = false;
      break;
    }
    else if( itx != x.end() && ity != y.end() )
    {
      x_f = itx->first;
      y_f = ity->first;
    }
    
  }
  while( itx != x.end() || ity != y.end() );
  
  if( eq == x.size() )
  {
    test = true;
  }
  
  return test;
}

bool pl_order::greater::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int alpha;
  int beta;
  unsigned int eq = 0;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int x_f = itx->first;
  int y_f = ity->first;
  
  do
  {
    if( x_f < y_f )
    {
      alpha = ity->second;
      beta = 0;
      itx++;
    }
    else if( x_f > y_f )
    {
      alpha = 0;
      beta = ity->second;
      ity++;
    }
    else if( x_f == y_f )
    {
      alpha = itx->second;
      beta = ity->second;
      itx++;
      ity++;
    }
    
    if( alpha > beta )
    {
      test = true;
      break;
    }
    else if( alpha < beta )
    {
      test = false;
      break;
    }
    else if( alpha == beta )
    {
      eq++;
    }
    
    
    if( itx == x.end() && ity != y.end() )
    {
      test = false;
      break;
    }
    else if( itx != x.end() && ity == y.end() )
    {
      test = true;
      break;
    }
    else if( itx != x.end() && ity != y.end() )
    {
      x_f = itx->first;
      y_f = ity->first;
    }
    
  }
  while( itx != x.end() || ity != y.end() );
  
  if( eq == x.size() )
  {
    test = false;
  }
  
  return test;
}

bool pl_order::geq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int alpha;
  int beta;
  unsigned int eq = 0;
  
  Unitary_Monomial::const_iterator itx = x.begin();
  Unitary_Monomial::const_iterator ity = y.begin();
  int x_f = itx->first;
  int y_f = ity->first;
  
  do
  {
    if( x_f < y_f )
    {
      alpha = ity->second;
      beta = 0;
      itx++;
    }
    else if( x_f > y_f )
    {
      alpha = 0;
      beta = ity->second;
      ity++;
    }
    else if( x_f == y_f )
    {
      alpha = itx->second;
      beta = ity->second;
      itx++;
      ity++;
    }
    
    if( alpha > beta )
    {
      test = true;
      break;
    }
    else if( alpha < beta )
    {
      test = false;
      break;
    }
    else if( alpha == beta )
    {
      eq++;
    }
    
    
    if( itx == x.end() && ity != y.end() )
    {
      test = false;
      break;
    }
    else if( itx != x.end() && ity == y.end() )
    {
      test = true;
      break;
    }
    else if( itx != x.end() && ity != y.end() )
    {
      x_f = itx->first;
      y_f = ity->first;
    }
    
  }
  while( itx != x.end() || ity != y.end() );
  
  if( eq == x.size() )
  {
    test = true;
  }
  
  return test;
}

bool gl_order::equal::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    if( x.size() == y.size() )
    {
      int alpha;
      int beta;
      unsigned int eq = 0;
      
      Unitary_Monomial::const_iterator itx = x.begin();
      Unitary_Monomial::const_iterator ity = y.begin();
      int x_f = itx->first;
      int y_f = ity->first;
      
      do
      {
        if( x_f < y_f )
        {
          alpha = ity->second;
          beta = 0;
          itx++;
        }
        else if( x_f > y_f )
        {
          alpha = 0;
          beta = ity->second;
          ity++;
        }
        else if( x_f == y_f )
        {
          alpha = itx->second;
          beta = ity->second;
          itx++;
          ity++;
        }
        
        if( alpha > beta )
        {
          test = false;
          break;
        }
        else if( alpha < beta )
        {
          test = false;
          break;
        }
        else if( alpha == beta )
        {
          eq++;
        }
        
        
        if( itx == x.end() && ity != y.end() )
        {
          test = false;
          break;
        }
        else if( itx != x.end() && ity == y.end() )
        {
          test = false;
          break;
        }
        else if( itx != x.end() && ity != y.end() )
        {
          x_f = itx->first;
          y_f = ity->first;
        }
        
      }
      while( itx != x.end() || ity != y.end() );
      
      if( eq == x.size() )
      {
        test = true;
      }
    }
    else
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

bool gl_order::less::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_iterator itx = x.begin();
    Unitary_Monomial::const_iterator ity = y.begin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = ity->second;
        beta = 0;
        itx++;
      }
      else if( x_f > y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = false;
        break;
      }
      else if( alpha < beta )
      {
        test = true;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.end() && ity != y.end() )
      {
        test = true;
        break;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.end() || ity != y.end() );
    
    if( eq == x.size() )
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = true;
  }
  
  return test;
}

bool gl_order::leq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_iterator itx = x.begin();
    Unitary_Monomial::const_iterator ity = y.begin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = ity->second;
        beta = 0;
        itx++;
      }
      else if( x_f > y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = false;
        break;
      }
      else if( alpha < beta )
      {
        test = true;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.end() && ity != y.end() )
      {
        test = true;
        break;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.end() || ity != y.end() );
    
    if( eq == x.size() )
    {
      test = true;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = true;
  }
  
  return test;
}

bool gl_order::greater::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_iterator itx = x.begin();
    Unitary_Monomial::const_iterator ity = y.begin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = ity->second;
        beta = 0;
        itx++;
      }
      else if( x_f > y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = true;
        break;
      }
      else if( alpha < beta )
      {
        test = false;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.end() && ity != y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        test = true;
        break;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.end() || ity != y.end() );
    
    if( eq == x.size() )
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = true;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

bool gl_order::geq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_iterator itx = x.begin();
    Unitary_Monomial::const_iterator ity = y.begin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = ity->second;
        beta = 0;
        itx++;
      }
      else if( x_f > y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = true;
        break;
      }
      else if( alpha < beta )
      {
        test = false;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.end() && ity != y.end() )
      {
        test = false;
        break;
      }
      else if( itx != x.end() && ity == y.end() )
      {
        test = true;
        break;
      }
      else if( itx != x.end() && ity != y.end() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.end() || ity != y.end() );
    
    if( eq == x.size() )
    {
      test = true;
    }
  }
  else if( degx > degy )
  {
    test = true;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

bool grl_order::equal::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    if( x.size() == y.size() )
    {
      int alpha;
      int beta;
      unsigned int eq = 0;
      
      Unitary_Monomial::const_reverse_iterator itx = x.rbegin();
      Unitary_Monomial::const_reverse_iterator ity = y.rbegin();
      int x_f = itx->first;
      int y_f = ity->first;
      
      do
      {
        if( x_f < y_f )
        {
          alpha = 0;
          beta = ity->second;
          ity++;
        }
        else if( x_f > y_f )
        {
          alpha = itx->second;
          beta = 0;
          itx++;
        }
        else if( x_f == y_f )
        {
          alpha = itx->second;
          beta = ity->second;
          itx++;
          ity++;
        }
        
        if( alpha > beta )
        {
          test = false;
          break;
        }
        else if( alpha < beta )
        {
          test = false;
          break;
        }
        else if( alpha == beta )
        {
          eq++;
        }
        
        
        if( itx == x.rend() && ity != y.rend() )
        {
          test = false;
          break;
        }
        else if( itx != x.rend() && ity == y.rend() )
        {
          test = false;
          break;
        }
        else if( itx != x.rend() && ity != y.rend() )
        {
          x_f = itx->first;
          y_f = ity->first;
        }
        
      }
      while( itx != x.rend() || ity != y.rend() );
      
      if( eq == x.size() )
      {
        test = true;
      }
    }
    else
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

bool grl_order::less::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_reverse_iterator itx = x.rbegin();
    Unitary_Monomial::const_reverse_iterator ity = y.rbegin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f > y_f )
      {
        alpha = itx->second;
        beta = 0;
        itx++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = true;
        break;
      }
      else if( alpha < beta )
      {
        test = false;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.rend() && ity != y.rend() )
      {
        test = false;
        break;
      }
      else if( itx != x.rend() && ity == y.rend() )
      {
        test = true;
        break;
      }
      else if( itx != x.rend() && ity != y.rend() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.rend() || ity != y.rend() );
    
    if( eq == x.size() )
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = true;
  }
  
  return test;
}

bool grl_order::leq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_reverse_iterator itx = x.rbegin();
    Unitary_Monomial::const_reverse_iterator ity = y.rbegin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f > y_f )
      {
        alpha = itx->second;
        beta = 0;
        itx++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = true;
        break;
      }
      else if( alpha < beta )
      {
        test = false;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.rend() && ity != y.rend() )
      {
        test = false;
        break;
      }
      else if( itx != x.rend() && ity == y.rend() )
      {
        test = true;
        break;
      }
      else if( itx != x.rend() && ity != y.rend() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.rend() || ity != y.rend() );
    
    if( eq == x.size() )
    {
      test = true;
    }
  }
  else if( degx > degy )
  {
    test = false;
  }
  else if( degx < degy )
  {
    test = true;
  }
  
  return test;
}

bool grl_order::greater::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_reverse_iterator itx = x.rbegin();
    Unitary_Monomial::const_reverse_iterator ity = y.rbegin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f > y_f )
      {
        alpha = itx->second;
        beta = 0;
        itx++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = false;
        break;
      }
      else if( alpha < beta )
      {
        test = true;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.rend() && ity != y.rend() )
      {
        test = true;
        break;
      }
      else if( itx != x.rend() && ity == y.rend() )
      {
        test = false;
        break;
      }
      else if( itx != x.rend() && ity != y.rend() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.rend() || ity != y.rend() );
    
    if( eq == x.size() )
    {
      test = false;
    }
  }
  else if( degx > degy )
  {
    test = true;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

bool grl_order::geq::operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const
{
  bool test;
  int degx = x.degree();
  int degy = y.degree();
  
  if( degx == degy )
  {
    int alpha;
    int beta;
    unsigned int eq = 0;
    
    Unitary_Monomial::const_reverse_iterator itx = x.rbegin();
    Unitary_Monomial::const_reverse_iterator ity = y.rbegin();
    int x_f = itx->first;
    int y_f = ity->first;
    
    do
    {
      if( x_f < y_f )
      {
        alpha = 0;
        beta = ity->second;
        ity++;
      }
      else if( x_f < y_f )
      {
        alpha = itx->second;
        beta = 0;
        itx++;
      }
      else if( x_f == y_f )
      {
        alpha = itx->second;
        beta = ity->second;
        itx++;
        ity++;
      }
      
      if( alpha > beta )
      {
        test = false;
        break;
      }
      else if( alpha < beta )
      {
        test = true;
        break;
      }
      else if( alpha == beta )
      {
        eq++;
      }
      
      
      if( itx == x.rend() && ity != y.rend() )
      {
        test = true;
        break;
      }
      else if( itx != x.rend() && ity == y.rend() )
      {
        test = false;
        break;
      }
      else if( itx != x.rend() && ity != y.rend() )
      {
        x_f = itx->first;
        y_f = ity->first;
      }
      
    }
    while( itx != x.rend() || ity != y.rend() );
    
    if( eq == x.size() )
    {
      test = true;
    }
  }
  else if( degx > degy )
  {
    test = true;
  }
  else if( degx < degy )
  {
    test = false;
  }
  
  return test;
}

/*__________________________________________________________________________________________________
 *    Polynome class
 */
template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >::Polynome()
{
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >::~Polynome()
{
  coefficients.clear();
}


template< typename Monomial_Order, typename Ring >
const int Polynome< Monomial_Order, Ring >::incognites() const
{
  return 0;
}

template< typename Monomial_Order, typename Ring >
int Polynome< Monomial_Order, Ring >::degree() const
{
  return coefficients.rbegin()->first.degree();
}

/*template< typename Monomial_Order, typename Ring >
  const std::string Polynome< Monomial_Order, Ring >::order() const
  {
  return const_cast< std::string >( monomial_order );
  }*/

/*template< typename Monomial_Order, typename Ring >
  Polynome< Monomial_Order, Ring >::iterator Polynome< Monomial_Order, Ring >::begin()
  {
  return coefficients.begin();
  }*/

template< typename Monomial_Order, typename Ring >
Unitary_Monomial& Polynome< Monomial_Order, Ring >::LM()
{
  //    return const_cast< Unitary_Monomial& >( coefficients.rbegin()->first );
  Unitary_Monomial* u = new Unitary_Monomial( coefficients.rbegin()->first );
  return *u;
}

template< typename Monomial_Order, typename Ring >
const Unitary_Monomial& Polynome< Monomial_Order, Ring >::LM() const
{
  Unitary_Monomial* u = new Unitary_Monomial( coefficients.rbegin()->first );
  return const_cast< Unitary_Monomial& >( *u );
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >& Polynome< Monomial_Order, Ring >::LT()
{
  Polynome< Monomial_Order, Ring >* r = new Polynome< Monomial_Order, Ring >();
  r->_coefficients()[ coefficients.rbegin()->first ] = coefficients.rbegin()->second;
  return *r;
}

template< typename Monomial_Order, typename Ring >
const Polynome< Monomial_Order, Ring >& Polynome< Monomial_Order, Ring >::LT() const
{
  Polynome< Monomial_Order, Ring >* r = new Polynome< Monomial_Order, Ring >();
  r->_coefficients()[ coefficients.rbegin()->first ] = coefficients.rbegin()->second;
  return const_cast< Polynome< Monomial_Order, Ring >& >( *r );
}

template< typename Monomial_Order, typename Ring >
const Ring& Polynome< Monomial_Order, Ring >::CLT() const
{
  return const_cast< Ring& >( coefficients.rbegin()->second );
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator< ( const Polynome< Monomial_Order, 
               Ring >& polynome ) const
{
  return Monomial_Order::less()( this->LM(), polynome->LM() );
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator<= ( const Polynome< Monomial_Order, 
                Ring >& polynome ) const
{
  return Monomial_Order::leq()( this->LM(), polynome->LM() );
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator> ( const Polynome< Monomial_Order, 
               Ring >& polynome ) const
{
  return Monomial_Order::greater()( this->LM(), polynome->LM() );
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator>= ( const Polynome< Monomial_Order, 
                Ring >& polynome ) const
{
  return Monomial_Order::geq()( this->LM(), polynome->LM() );
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator== ( const Polynome< Monomial_Order, 
                Ring >& polynome ) const
{
  if( this == &polynome )
  {
    return true;
  }
  else
  {
    if( coefficients.size() == polynome._coefficients().size() )
    {
      typename std::map< Unitary_Monomial, Ring, 
      typename Monomial_Order::less >::const_iterator it = coefficients.begin();
      typename std::map< Unitary_Monomial, Ring, 
      typename Monomial_Order::less >::const_iterator itpol =
      polynome._coefficients().begin();
      
      for( it = coefficients.begin(); it != coefficients.end(); ++it )
      {
        if( it != itpol )
        {
          return false;
          break;
        }
        
        ++itpol;
      }
      
      if( it == coefficients.end() )
      {
        return true;
      }
    }
    else
    {
      return false;
    }
  }
}

template< typename Monomial_Order, typename Ring >
bool Polynome< Monomial_Order, Ring >::operator!= ( const Polynome< Monomial_Order, 
                Ring >& polynome ) const
{
  if( this != &polynome )
  {
    return true;
  }
  else
  {
    if( coefficients.size() == polynome._coefficients().size() )
    {
      typename std::map< Unitary_Monomial, Ring, 
      typename Monomial_Order::less >::const_iterator it;
      typename std::map< Unitary_Monomial, Ring, 
      typename Monomial_Order::less >::const_iterator itpol = 
      polynome._coefficients().begin();
      
      for( it = coefficients.begin(); it != coefficients.end(); ++it )
      {
        if( it != itpol )
        {
          return true;
          break;
        }
        
        ++itpol;
      }
      
      if( it == coefficients.end() )
      {
        return false;
      }
    }
    else
    {
      return true;
    }
    
  }
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >&
Polynome< Monomial_Order, Ring >::operator= ( const Polynome< Monomial_Order, Ring >& polynome )
{
  if( this != &polynome )
  {
    coefficients.clear();
    typename std::map< Unitary_Monomial, Ring, 
    typename Monomial_Order::less >::const_iterator it;
    
    for( it = polynome._coefficients().begin(); it != polynome._coefficients().end(); ++it )
    {
      coefficients[ it->first ] = it->second;
    }
  }
  
  return *this;
}

template< typename Monomial_Order, typename Ring >
Ring& Polynome< Monomial_Order, Ring >::operator[]( const Unitary_Monomial& x )
{
  return coefficients[ x ];
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >&
Polynome< Monomial_Order, Ring >::operator+= ( const Polynome< Monomial_Order, Ring >& x )
{
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator it,aux;
  Ring val;
  
  for( it = x._coefficients().begin(); it != x._coefficients().end(); ++it )
  {
    aux = coefficients.find( it->first );
    
    if( aux != coefficients.end() )
    {
      val = aux->second + it->second;
      
      if( val != 0 )
      {
        coefficients[ it->first ] =  val;
      }
      else
      {
        coefficients.erase( it->first );
      }
    }
    else
    {
      coefficients[ it->first ] = it->second;
    }
  }
  
  return *this;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >&
Polynome< Monomial_Order, Ring >::operator-= ( const Polynome< Monomial_Order, Ring >& x )
{
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator it,
  aux;
  Ring val;
  
  for( it = x._coefficients().begin(); it != x._coefficients().end(); ++it )
  {
    aux = coefficients.find( it->first );
    
    if( aux != coefficients.end() )
    {
      val = aux->second - it->second;
      
      if( val != 0 )
      {
        coefficients[ it->first ] =  val;
      }
      else
      {
        coefficients.erase( it->first );
      }
    }
    else
    {
      coefficients[ it->first ] = -it->second;
    }
  }
  
  return *this;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >&
Polynome< Monomial_Order, Ring >::operator*= ( std::pair< Unitary_Monomial, Ring >& x )
{
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::iterator it;
  std::map< Unitary_Monomial, Ring > coef;
  
  for( it = coefficients.begin(); it != coefficients.end(); ++it )
  {
    coef[ x.first * it->first ] = x.second * it->second;
  }
  
  coefficients.clear();
  
  for( it = coef.begin(); it != coef.end(); ++it )
  {
    coefficients[ it->first ] = it->second;
  }
  
  return *this;
}

template< typename Monomial_Order, typename Ring >
std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >& 
Polynome< Monomial_Order, Ring >::_coefficients()
{
  return coefficients;
}

template< typename Monomial_Order, typename Ring >
const std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >&
Polynome< Monomial_Order, Ring >::_coefficients() const
{
  return const_cast< std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >& >( coefficients );
};

//__________________________________________________________________________________________________
template< typename Monomial_Order, typename Ring >
std::ostream& operator<< ( std::ostream& out, const Polynome< Monomial_Order, Ring >& x )
{
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less
>::const_reverse_iterator it;
  
  out << std::endl;
  
  for( it = x._coefficients().rbegin(); it != ( --x._coefficients().rend() ); ++it )
  {
    out << "  " << it->second << " " << it->first << " +";
  }
  
  out << "  " << it->second << " " << it->first;
  out << std::endl;
  return out;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator+ ( const Polynome< Monomial_Order, Ring >& x,
            const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator it, aux;
  r = x;
  
  for( it = y._coefficients().begin(); it != y._coefficients().end(); ++it )
  {
    aux = r._coefficients().find( it->first );
    
    if( aux != r._coefficients().end() )
    {
      val = it->second + aux->second;
      
      if( val != 0 )  // val != Ring::null
      {
      r._coefficients()[ it->first ] = val;
    }
    else
    {
      r._coefficients().erase( it->first );
    }
    }
    else
    {
      r._coefficients()[ it->first ] = it->second;
    }
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator+ ( const Polynome< Monomial_Order, Ring >& x,
            const Unitary_Monomial& u )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator aux;
  r = x;
  
  aux = r._coefficients().find( u );
  
  if( aux != r._coefficients().end() )
  {
    val = aux->second + 1; // Ring::unity;
    
    if( val != 0 )  // val != Ring::null
  {
    r._coefficients()[ u ] = val;
  }
  else
  {
    r._coefficients().erase( u );
  }
  }
  else
  {
    r._coefficients()[ u ] = 1; // Ring::unity;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator+ ( const Unitary_Monomial& u,
            const Polynome< Monomial_Order, Ring >& x )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator aux;
  r = x;
  
  aux = r._coefficients().find( u );
  
  if( aux != r._coefficients().end() )
  {
    val = 1 + aux->second; // Ring::unity;
    
    if( val != 0 )  // val != Ring::null
  {
    r._coefficients()[ u ] = val;
  }
  else
  {
    r._coefficients().erase( u );
  }
  }
  else
  {
    r._coefficients()[ u ] = 1; // Ring::unity;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator- ( const Polynome< Monomial_Order, Ring >& x,
            const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator it, aux;
  r = x;
  
  for( it = y._coefficients().begin(); it != y._coefficients().end(); ++it )
  {
    aux = r._coefficients().find( it->first );
    
    if( aux != r._coefficients().end() )
    {
      val = aux->second - it->second;
      
      if( val != 0 )
      {
        r._coefficients()[ it->first ] = val;
      }
      else
      {
        r._coefficients().erase( it->first );
      }
    }
    else
    {
      r._coefficients()[ it->first ] = -it->second;
    }
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator- ( const Polynome< Monomial_Order, Ring >& x,
            const Unitary_Monomial& u )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator aux;
  r = x;
  
  aux = r._coefficients().find( u );
  
  if( aux != r._coefficients().end() )
  {
    val = aux->second - 1; // Ring::unity;
    
    if( val != 0 )  // val != Ring::null
  {
    r._coefficients()[ u ] = val;
  }
  else
  {
    r._coefficients().erase( u );
  }
  }
  else
  {
    r._coefficients()[ u ] = -1; // Ring::unity;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator- ( const Unitary_Monomial& u,
            const Polynome< Monomial_Order, Ring >& x )
{
  Polynome< Monomial_Order, Ring > r;
  Ring val;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator aux;
  r = x;
  
  aux = r._coefficients().find( u );
  
  if( aux != r._coefficients().end() )
  {
    val = 1 - aux->second; // Ring::unity;
    
    if( val != 0 )  // val != Ring::null
  {
    r._coefficients()[ u ] = val;
  }
  else
  {
    r._coefficients().erase( u );
  }
  }
  else
  {
    r._coefficients()[ u ] = 1; // Ring::unity;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator* ( const Polynome< Monomial_Order, Ring >& x,
            const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > r;
  Unitary_Monomial mp;
  Ring rp, val;
  
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator itx, ity;
  
  for( itx = x._coefficients().begin(); itx != x._coefficients().end(); ++itx )
  {
    for( ity = y._coefficients().begin(); ity != y._coefficients().end(); ++ity )
    {
      mp = itx->first * ity->first;
      rp = itx->second * ity->second;
      
      if( r._coefficients().find( mp ) != r._coefficients().end() )
      {
        val = r[ mp ] + rp;
        
        if( val != 0 )
        {
          r[ mp ] = val;
        }
        else
        {
          r._coefficients().erase( mp );
        }
      }
      else
      {
        r[ mp ] = rp;
      }
    }
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Polynome< Monomial_Order, Ring >& x, 
               const Unitary_Monomial& u )
{
  Polynome< Monomial_Order, Ring > r;
  Unitary_Monomial mp;
  Ring rp;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator itx;
  
  for( itx = x._coefficients().begin(); itx != x._coefficients().end(); ++itx )
  {
    mp = itx->first * u;
    rp = itx->second; // Suppose that Ring::unity exist
    r[ mp ] = rp;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Unitary_Monomial& u,
               const Polynome< Monomial_Order, Ring >& x )
{
  Polynome< Monomial_Order, Ring > r;
  Unitary_Monomial mp;
  Ring rp;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator itx;
  
  for( itx = x._coefficients().begin(); itx != x._coefficients().end(); ++itx )
  {
    mp = itx->first * u;
    rp = itx->second; // Suppose that Ring::unity exist
    r[ mp ] = rp;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Polynome< Monomial_Order, Ring >& x, 
               const Ring& c )
{
  Polynome< Monomial_Order, Ring > r;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator it;
  
  for( it = x._coefficients().begin(); it != x._coefficients().end(); ++it )
  {
    r[ it->first ] = it->second * c;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Ring& c,
               const Polynome< Monomial_Order, Ring >& x )
{
  Polynome< Monomial_Order, Ring > r;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator it;
  
  for( it = x._coefficients().begin(); it != x._coefficients().end(); ++it )
  {
    r[ it->first ] = it->second * c;
  }
  
  return r;
}

/*template< typename Monomial_Order, typename Ring >
  Polynome< Monomial_Order, Ring >
  operator* ( std::map< Unitary_Monomial, Ring >::const_iterator& x,
  const Polynome< Monomial_Order, Ring >& y )
  {
  Polynome< Monomial_Order, Ring > r;
  Unitary_Monomial mp;
  Ring rp;

  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator it;

  for ( it = y._coefficients().begin(); it != y._coefficients().end(); ++it )
  {
  mp = x->first * it->first;
  rp = x->second * it->second;

  if ( r._coefficients().find( mp ) != r._coefficients().end() )
  {
  r[ mp ] = rp + r[ mp ];
  }
  else
  {
  r[ mp ] = rp;
  }
  }

  return r;
  }*/

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator/ ( const Polynome< Monomial_Order, Ring >& x, 
      const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > r;
  Polynome< Monomial_Order, Ring > g = x;
  Unitary_Monomial LMD, i;
  Ring val, gyC;
  
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator it, aux;
  
  while( y.LM() | g.LM() )
  {
    LMD = g.LM() / y.LM();
    gyC = g._coefficients().rbegin()->second / y._coefficients().rbegin()->second;
    
    if( r._coefficients().find( LMD ) != r._coefficients().end() )
    {
      val = gyC + r[ LMD ];
      
      if( val != 0 )
      {
        r._coefficients()[ LMD ] = val;
      }
    }
    else
    {
      r._coefficients()[ LMD ] = gyC;
    }
    
    g._coefficients().erase( g.LM() );
    
    for( it = y._coefficients().begin(); it != ( --y._coefficients().end() ); ++it )
    {
      i = it->first * LMD;
      aux = g._coefficients().find( i );
      
      if( aux != g._coefficients().end() )
      {
        val = aux->second - it->second * gyC;
        
        if( val != 0 )
        {
          g._coefficients()[ i ] = val;
        }
      }
      else
      {
        g._coefficients()[ i ] = -it->second * gyC;
      }
    }
    
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator/ ( const Polynome< Monomial_Order, Ring >& x,
               const Ring& c )
{
  Polynome< Monomial_Order, Ring > r;
  
  typename std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::const_iterator it;
  
  for( it = x._coefficients().begin(); it != x._coefficients().end(); ++it )
  {
    r[ it->first ] = it->second / c;
  }
  
  return r;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring >
operator% ( const Polynome< Monomial_Order, Ring >& x,
      const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > g = x;
  Unitary_Monomial LMD, i;
  Ring val, gyC;
  
  typename std::map< Unitary_Monomial, Ring, 
  typename Monomial_Order::less >::const_iterator it, aux;
  
  while( y.LM() | g.LM() )
  {
    LMD = g.LM() / y.LM();
    gyC = g._coefficients().rbegin()->second / y._coefficients().rbegin()->second;
    
    g._coefficients().erase( g.LM() );
    
    for( it = y._coefficients().begin(); it != ( --y._coefficients().end() ); ++it )
    {
      i = it->first * LMD;
      aux = g._coefficients().find( i );
      
      if( aux != g._coefficients().end() )
      {
        val = aux->second - it->second * gyC;
        
        if( val != 0 )
        {
          g._coefficients()[ i ] = val;
        }
      }
      else
      {
        g._coefficients()[ i ] = -it->second * gyC;
      }
    }
  }
  
  return g;
}

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > S_polynomial( const Polynome< Monomial_Order, Ring >& x,
                                               const Polynome< Monomial_Order, Ring >& y )
{
  Polynome< Monomial_Order, Ring > S;
  Unitary_Monomial lcm = LCM( x.LM(), y.LM() );
  S = ( lcm / x.LM() ) * x / x.CLT()  - ( lcm / y.LM() ) * y / y.CLT();
  return S;
}

