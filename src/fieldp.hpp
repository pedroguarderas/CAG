/*__________________________________________________________________________________________________

    autor: Pedro Guarderas
    email: pedro.felipe.guarderas@gmail.com
    date: 08-12-2012
    file: field.hpp
 
  This program is free software; you can redistribute it and/or modify it under the 
  terms of the GNU General Public License as published by the Free Software Foundation; 
  either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#ifndef FIELDP
#define FIELDP

#include <list>
#include <string>
#include <iostream>
#include <vector>

/*__________________________________________________________________________________________________
 *    Error test prime class
 */
template< typename Z = int >
class PrimeTest {
public:
  PrimeTest( const Z& );
  ~PrimeTest();
  
  const Z* _p;
};

std::ostream& operator << ( std::ostream& out, const PrimeTest& PT  ) {
  out << "Prime Test Fail for: " <<  PT._p << std::endl;
}


/*__________________________________________________________________________________________________
 *    Prime Field
 */
template< typename Z = int >
class PrimeField {
public:
  PrimeField( const Z& p );
  ~PrimeField();
  
private:
  static const Z prime;
  unsigned char n : sizeof(Z);
};

// Based in AKS algorithm
template< typename Sqrt, typename Log, typename Z = int >
bool test_prime( const Z& n, std::vector< Z >& plist ) {
  bool test = true;
  Z a = Z( 2 );
  
  for ( ; a < Sqrt( n ); a++ ) {
    if ( n % a == Z( 0 ) ) {
      test = false;
      break;
    }
  }
  
  a = Z( 2 );
  if ( test ) {
    while ( a < n ) {
      if ( GCD( n, a ) == Z( 1 ) ) {
        if ( a > Z( 2 ) ) {
          
        }
      }
      else {
        test = false;
        break;
      }
    }
  }
  return test;
}

template< typename Z >
PrimeField< Z > operator+ ( const Z& x, const Z& y );

template< typename Z >
PrimeField< Z > operator- ( const Z& x, const Z& y );

template< typename Z >
PrimeField< Z > operator* ( const Z& x, const Z& y );

template< typename Z >
PrimeField< Z > operator/ ( const Z& x, const Z& y );


/*__________________________________________________________________________________________________
 *    Finite Field
 */
template< typename Z = int >
class FiniteField {
public:
  FiniteField( const Z& p, const Z& n );
  ~FiniteField();
  Z generator( const Z& p, const Z& n ) const;
  
private:
  static const Z prime;
  static const Z power;
  static const Z irred;
  static const Z size;
};

template< typename Z >
FiniteField< Z > operator+ ( const FieldZ& x, const Z& y );

template< typename Z >
FiniteField< Z > operator- ( const Z& x, const Z& y );

template< typename Z >
FiniteField< Z > operator* ( const Z& x, const Z& y );

template< typename Z >
FiniteField< Z > operator/ ( const Z& x, const Z& y );

/*__________________________________________________________________________________________________
 *    Sieve Methods
 */
template< typename Z >
std::list< Z > SieveSundaram( const Z& p, const Z& n );

template< typename Z >
std::list< int > SieveErastosthenes( std::list< Z > v );

#endif
