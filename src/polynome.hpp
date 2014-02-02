/*__________________________________________________________________________________________________

		autor: Pedro Guarderas
		email: ajusworkopensource@gmail.com
		date: 11-05-2010
		file: polynome.hpp
 
	This program is free software; you can redistribute it and/or modify it under the 
	terms of the GNU General Public License as published by the Free Software Foundation; 
	either version 2 of the License, or (at your option) any later version.
____________________________________________________________________________________________________
*/

#ifndef POLYNOME
#define POLYNOME

//#include <allocator>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "unitary_monomial.hpp"


/*__________________________________________________________________________________________________
 *		Funcional objects ( operators ) for monomial comparation
 */
struct Monomial_Order_Operator : 
public std::binary_function< Unitary_Monomial, Unitary_Monomial, bool > 
{
  virtual bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const = 0;
};

/*__________________________________________________________________________________________________
 *		Pure lexicographic functional object 
 */
struct pl_order
{
  struct equal : public Monomial_Order_Operator 
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct less : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct leq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct greater : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct geq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
};

/*__________________________________________________________________________________________________
 *		Graded lexicographic functional object 
 */
struct gl_order
{
  struct equal : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct less : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct leq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct greater : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct geq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
};

/*__________________________________________________________________________________________________
 *		Graded reverse lexicographic functional object
 */
struct grl_order
{
  struct equal : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct less : public  Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct leq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct greater : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
  
  struct geq : public Monomial_Order_Operator
  {
    bool operator()( const Unitary_Monomial& x, const Unitary_Monomial& y ) const;
  };
};


/*__________________________________________________________________________________________________
 *		Polynome class
 */
template< typename Monomial_Order = grl_order, typename Ring = float >
class Polynome
{
public:
  Polynome();
  ~Polynome();
  
  struct iterator : 
  public std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::iterator
  {
    Unitary_Monomial& LM() { return this->first; }
    Ring& coef() { return this->second; }
  };
  
  struct const_iterator : 
  public std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >::iterator
  {
    const Unitary_Monomial& LM() { return const_cast< Unitary_Monomial& >( this->first ); }
    const Ring& coef() { return const_cast< Ring& >( this->second ); }
  };
  
  const int incognites() const;
  int degree() const;
  //    const std::string order() const;
  
  //    iterator begin();
  //    iterator end();
  //    const_iterator begin();
  //    const_iterator end();
  
  Unitary_Monomial& LM(); // Leading monomial
  const Unitary_Monomial& LM() const; // Leading monomial
  Polynome< Monomial_Order, Ring >& LT(); // Leading term
  const Polynome< Monomial_Order, Ring >& LT() const; // Leading term
  const Ring& CLT() const; // Leading monomial coefficient respect to order
  
  bool operator< ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  bool operator<= ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  bool operator> ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  bool operator>= ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  bool operator== ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  bool operator!= ( const Polynome< Monomial_Order, Ring >& polynome ) const;
  
  Polynome< Monomial_Order, Ring >& operator= ( const Polynome< Monomial_Order, Ring >& polynome );
  Polynome< Monomial_Order, Ring >& operator+= ( const Polynome< Monomial_Order, Ring >& x );
  Polynome< Monomial_Order, Ring >& operator-= ( const Polynome< Monomial_Order, Ring >& x );
  Polynome< Monomial_Order, Ring >& operator*= ( std::pair< Unitary_Monomial, Ring >& x );
  
  Ring& operator[]( const Unitary_Monomial& x );
  
  std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >& _coefficients();
  const std::map< Unitary_Monomial, Ring, typename Monomial_Order::less >& _coefficients() const;
  
private:
  std::map< Unitary_Monomial, Ring, typename Monomial_Order::less > coefficients;
  
};

/*__________________________________________________________________________________________________
 *		Definition of operators
 */
template< typename Monomial_Order, typename Ring >
std::ostream& operator<< ( std::ostream& out, const Polynome< Monomial_Order, Ring >& x );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator+ ( const Polynome< Monomial_Order, Ring >& x,
                                             const Polynome< Monomial_Order, Ring >& y );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator+ ( const Polynome< Monomial_Order, Ring >& x,
                                             const Unitary_Monomial& u );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator+ ( const Unitary_Monomial& u,
                                             const Polynome< Monomial_Order, Ring >& x );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator- ( const Polynome< Monomial_Order, Ring >& x,
                                             const Polynome< Monomial_Order, Ring >& y );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator- ( const Polynome< Monomial_Order, Ring >& x,
                                             const Unitary_Monomial& u );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator- ( const Unitary_Monomial& u,
                                             const Polynome< Monomial_Order, Ring >& x );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Polynome< Monomial_Order, Ring >& x,
                                             const Polynome< Monomial_Order, Ring >& y );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Polynome< Monomial_Order, Ring >& x,
                                             const Unitary_Monomial& u );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Unitary_Monomial& u,
                                             const Polynome< Monomial_Order, Ring >& x );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Polynome< Monomial_Order, Ring >& x,
                                             const Ring& c );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator* ( const Ring& c,
                                             const Polynome< Monomial_Order, Ring >& x );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator/ ( const Polynome< Monomial_Order, Ring >& x, 
                                             const Polynome< Monomial_Order, Ring >& y );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator/ ( const Polynome< Monomial_Order, Ring >& x, 
                                             const Ring& c );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > operator% ( const Polynome< Monomial_Order, Ring >& x,
                                             const Polynome< Monomial_Order, Ring >& y );

template< typename Monomial_Order, typename Ring >
Polynome< Monomial_Order, Ring > S_polynomial( const Polynome< Monomial_Order, Ring >& x,
                                               const Polynome< Monomial_Order, Ring >& y );

/*__________________________________________________________________________________________________
 *		Include for template compilation
 */
#include "polynome.cpp"

#endif // POLYNOME
