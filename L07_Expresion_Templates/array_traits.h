/*
 * helper traits class to select how to refer to an "expression template node"
 * - in general: by reference 
 * - for scalars: by value 
 */ 

#ifndef _ARRAY_TRAITS_H
#define _ARRAY_TRAITS_H

template <typename T> class A_Scalar; 

// primary template 
template <typename T> 
class A_Traits { 
public: 
    typedef T const& ExprRef;  // constant reference 
}; 

// partial specialization for scalars 
template <typename T> 
class A_Traits<A_Scalar<T> > { 
public: 
    typedef A_Scalar<T> ExprRef;  // ordinary value
};

#endif
