/*__________________________________________________________________________________________________

        autor: Pedro Guarderas
        email: ajusworkopensource@gmail.com
        date: 2012-12-08
        file: fieldp.cpp

    This program is free software; you can redistribute it and/or modify it under the terms of the
    GNU General Public License as published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
  ________________________________________________________________________________________________*/

#include "fieldp.hpp"


/*__________________________________________________________________________________________________
 */
template< typename Z >
PrimeField< Z >::PrimeField( const Z& p ) : prime( p ) {
}

template< typename Z >
PrimeField< Z >::~PrimeField() {
}

template< typename Z >
PrimeField< Z > operator+ ( const Z& x, const Z& y ) {
    return ( x + y ) % p;
}

template< typename Z >
PrimeField< Z > operator- ( const Z& x, const Z& y ) {
    return ( x - y ) % p;
}

template< typename Z >
PrimeField< Z > operator* ( const Z& x, const Z& y ) {
    return ( x * y ) % p;
}

template< typename Z >
PrimeField< Z > operator/ ( const Z& x, const Z& y ) {
    return ( x / y ) % p;
}

/*__________________________________________________________________________________________________
 */
template< typename Z >
FiniteField< Z >::FiniteField( const Z& p, const Z& n )
    : prime( p ),
      power( n ) {
    size = pow( p, n );
    irred = generator( p, n );
}

template< typename Z >
FiniteField< Z >::~FiniteField() {
}

template< typename Z >
Z FiniteField< Z >::generator( const Z &p, const Z &n ) const {
    std::list< Z > v;
    Z a = pow( p, n );
    Z b = 2*a-1;

    for ( Z i = a; i <= b; i++ ) {
        v.push_back( i );
    }

    for ( Z p = 2; p <= b / 2; p++ ) {
        for ( Z i = ( a - a % p ) / p; i <= ( b - b % p ) / p; i++ ) {
            v.remove( i*p );
        }
    }
    return v.front();
}

template< typename Z >
FiniteField< Z > operator+ ( const Z& x, const Z& y ) {
    return ( x + y ) % irred;
}

template< typename Z >
FiniteField< Z > operator- ( const Z& x, const Z& y ) {
    return ( x - y ) % irred;
}

template< typename Z >
FiniteField< Z > operator* ( const Z& x, const Z& y ) {
    Z f = x * y;
    Z g = ( x * y ) % size;
    return ( irred % size )*( f - g ) / size;

}

template< typename Z >
FiniteField< Z > operator/ ( const Z& x, const Z& y ) {
    return ( x / y ) % p;
}


/*__________________________________________________________________________________________________
 */
template< typename Z >
std::list< Z > SieveSundaram( const Z& p, const Z& n ) {
//    int x = pow( p, n );
//    int y = pow( p, n + 1 ) - 1;
//    int a = ( x - x%2 )/ 2 - 1;
//    int b = ( y - y%2 )/ 2;
//    list< int > v;

//    for ( int k = a; k <= b; k++ ) {
//        if ( k % 2 == 1 ) v.push_back( k );
//    }
//    for ( int i = 1; i <= b; i++ ) {
//        for ( int j = i; j <= b; j++ ) {
//            int z = i + j + 2*i*j;
//            if ( z <= b ) v.remove( z );
//        }
//    }
    std::list< Z > w;
//    for ( list<int>::const_iterator k = v.begin(); k != v.end(); ++k ) {
//        w.push_back( 2*(*k) + 1 );
//    }
    return w;
}

template< typename Z >
std::list< int > SieveErastosthenes( std::list< Z > v ) {
    Z b = v.back();
    Z a = v.front();
    for ( Z p = 2; p <= b / 2; p++ ) {
        for ( Z i = ( a - a % p ) / p; i <= ( b - b % p ) / p; i++ ) {
            v.remove( i*p );
        }
    }
    return v;
}

