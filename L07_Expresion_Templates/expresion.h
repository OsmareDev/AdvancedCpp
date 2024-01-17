/**
 * Class Array implemented using expression templates
 * Obtained from theory slides of PROA and book C++ templates: The complete guide
 * 
 */

#ifndef _EXPRESION_H
#define _EXPRESION_H

#include <cassert>
#include <iostream>
#include <cmath>
#include "sarray.h"
#include "array_traits.h"

/*
 * Classes for representing operations
 */
template <typename T, typename OP1, typename OP2> 
class A_Add 
{ 
    typename A_Traits<OP1>::ExprRef op1;    // first operand 
    typename A_Traits<OP2>::ExprRef op2;    // second operand 

public: 
    // constructor initializes references to operands 
    A_Add (OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        return op1[idx] + op2[idx]; 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 

    // return type of the expression
    static std::string type() 
    {
        return "A_Add<" + OP1::type() + "," + OP2::type() + ">";  
    }
}; 

template <typename T, typename OP1, typename OP2> 
class A_Mult 
{ 
    typename A_Traits<OP1>::ExprRef op1;    // first operand 
    typename A_Traits<OP2>::ExprRef op2;    // second operand 

public: 
    // constructor initializes references to operands 
    A_Mult(OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        return op1[idx] * op2[idx]; 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 

    // return type of the expression
    static std::string type() 
    {
        return "A_Mult<" + OP1::type() + "," + OP2::type() + ">";  
    }
}; 


/**********************************************************************/ /**
 *
 *  Class A_Pow, to raise an array to a power
   *
   * @param T type of the array elements
   * @param OP1 type of the expression to raise
   * @param OP2 type of the expression that represents the power
 * 
 */ /**********************************************************************/
template <typename T, typename OP1, typename OP2> 
class A_Pow
{ 
    typename A_Traits<OP1>::ExprRef op1;    // first operand 
    typename A_Traits<OP2>::ExprRef op2;    // second operand 

public: 
    // constructor initializes references to operands 
    A_Pow(OP1 const& a, OP2 const& b) : op1(a), op2(b) {} 

    // compute sum when value requested 
    T operator[] (size_t idx) const { 
        /* ONLY FOR INTEGER, BUT MORE EFFICIENT
        T aux = 1;
        for (size_t i = 0; i < op2[idx]; ++i)
            aux *= op1[idx];
        */
        
        return pow(op1[idx], op2[idx]); 
    } 

    // size is maximum size 
    size_t size() const { 
        assert (op1.size()==0 || op2.size()==0 
                || op1.size()==op2.size()); 
        return op1.size()!=0 ? op1.size() : op2.size(); 
    } 

    // return type of the expression
    static std::string type() 
    {
        return "A_Pow<" + OP1::type() + "," + OP2::type() + ">";  
    }
}; 

/**********************************************************************/ /**
 *
 *  A_Sqrt class, to calculate the square root of an array
  *
  * @param T type of the array elements
  * @param OP1 type of the expression to raise
 *
*/ /**********************************************************************/
template <typename T> 
class A_Scalar 
{ 
    T const& s;  // value of the scalar 

public: 
    // constructor initializes value 
    A_Scalar (T const& v) : s(v) {} 

    // for index operations the scalar is the value of each element 
    T operator[] (size_t) const { 
        return s; 
    } 

    // scalars have zero as size 
    size_t size() const { 
        return 0; 
    }

    // return type of the expression
    static std::string type() 
    {
        return "A_Scalar";  
    }
}; 


/**********************************************************************/ /**
 *
 *  A_Sqrt class, to calculate the square root of an array
  *
  * @param T type of the array elements
  * @param OP1 type of the expression to raise
 *
*/ /**********************************************************************/
template <typename T, typename Rep = SArray<T> > 
class Array 
{ 
    Rep expr_rep;   // (access to) the data of the array 

protected:
    // return what the array currently represents 
    Rep const& rep() const { 
        return expr_rep; 
    } 
    Rep& rep() { 
        return expr_rep; 
    } 
    
public: 
    // create array with initial size 
    explicit Array (size_t s) : expr_rep(s) {} 

    // create array from possible representation 
    Array (Rep const& rb) : expr_rep(rb) {} 

    // create array from possible representation
    inline std::string type() {return "Array<" + expr_rep.type() + ">";}

    // index operator for constants and variables 
    T operator[] (size_t idx) const { 
        assert(idx<size()); 
        return expr_rep[idx]; 
    } 
    T& operator[] (size_t idx) { 
        assert(idx<size()); 
        return expr_rep[idx]; 
    } 
    
    // assignment operator for same type 
    Array& operator= (Array const& b) { 
        assert(size() == b.size()); 
        for (size_t idx = 0; idx < b.size(); ++idx) { 
            expr_rep[idx] = b[idx]; 
        } 
        return *this; 
    } 

    // assignment operator for arrays of different type 
    template<typename T2, typename Rep2> 
    Array& operator= (Array<T2, Rep2> const& b) { 
        assert(size() == b.size()); 
        for (size_t idx = 0; idx < b.size(); ++idx) { 
            expr_rep[idx] = b[idx]; 
        } 
        return *this; 
    } 

    // assignment operator for scalars
    size_t size() const { 
        return expr_rep.size(); 
    }

    // pow member function
    // parameter in: A_Scalar<T> const& b
    // parameter out: Array<T, A_Pow<T, Rep, A_Scalar<T>>>
    Array<T, A_Pow<T, Rep, A_Scalar<T>>> pow(T const &b);

    // Operator overloading
    // Operator +
    template <typename T2, typename R1, typename R2> 
    friend Array<T2,A_Add<T2,R1,R2>> 
    operator+ (Array<T2,R1> const& a, Array<T2,R2> const& b);

    template <typename T2, typename R2>
    friend Array<T2, A_Add<T2, A_Scalar<T2>, R2>> 
    operator+(T2 const &a, Array<T2, R2> const &b);

    template <typename T2, typename R1>
    friend Array<T2, A_Add<T2, R1, A_Scalar<T2>>> 
    operator+(Array<T2, R1> const &a, T2 const &b);
    
    // Operator *
    template <typename T2, typename R1, typename R2> 
    friend Array<T2,A_Mult<T2,R1,R2>> 
    operator*(Array<T2,R1> const& a, Array<T2,R2> const& b);

    template <typename T2, typename R2>
    friend Array<T2, A_Mult<T2, A_Scalar<T2>, R2>> 
    operator*(T2 const &a, Array<T2, R2> const &b);

    template <typename T2, typename R1>
    friend Array<T2, A_Mult<T2, R1, A_Scalar<T2>>> 
    operator*(Array<T2, R1> const &a, T2 const &b);
}; 


/**********************************************************************/ /**
 *
 *  Calculate the sum of two arrays
  *
  * @param [in] to array to add
  * @param [in] b array to add
  * @return array with the sum of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R1, typename R2> 
Array<T,A_Add<T,R1,R2> > operator+ (Array<T,R1> const& a, Array<T,R2> const& b) 
{ 
    return Array<T,A_Add<T,R1,R2> > 
           (A_Add<T,R1,R2>(a.rep(),b.rep())); 
} 

/**********************************************************************/ /**
 *
 *  Calculate the sum of an array with a scalar
  *
  * @param [in] to scale to sum
  * @param [in] b array to add
  * @return array with the sum of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R2> 
Array<T,A_Add<T,A_Scalar<T>,R2> > operator+ (T const& a, Array<T,R2> const& b) 
{ 
    return Array<T, A_Add<T, A_Scalar<T>, R2> > 
           (A_Add<T, A_Scalar<T>,R2>(A_Scalar<T>(a), b.rep())); 
} 

/**********************************************************************/ /**
 *
 *  Calculate the sum of an array with a scalar
  *
  * @param [in] to array to add
  * @param [in] b scalar to add
  * @return array with the sum of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R1> 
Array<T,A_Add<T,R1,A_Scalar<T>> > operator+ (Array<T, R1> const& a, T const& b) 
{ 
    return Array<T,A_Add<T,R1,A_Scalar<T>> > 
           (A_Add<T,R1,A_Scalar<T>>(a.rep(), A_Scalar<T>(b))); 
} 

/**********************************************************************/ /**
 *
 *  Calculate the multiplication of two arrays
  *
  * @param [in] to array to multiply
  * @param [in] b array to multiply
  * @return array with the multiplication of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R1, typename R2> 
Array<T,A_Mult<T,R1,R2> > operator* (Array<T,R1> const& a, Array<T,R2> const& b) 
{ 
    return Array<T,A_Mult<T,R1,R2> > 
           (A_Mult<T,R1,R2>(a.rep(),b.rep())); 
} 

/**********************************************************************/ /**
 *
 *  Calculate the multiplication of an array with a scalar
  *
  * @param [in] to scalar to multiply
  * @param [in] b array to multiply
  * @return array with the multiplication of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R2> 
Array<T,A_Mult<T,A_Scalar<T>,R2> > operator* (T const& a, Array<T,R2> const& b) 
{ 
    return Array<T, A_Mult<T, A_Scalar<T>, R2> > 
           (A_Mult<T, A_Scalar<T>,R2>(A_Scalar<T>(a), b.rep())); 
} 

/**********************************************************************/ /**
 *
 *  Calculate the multiplication of an array with a scalar
  *
  * @param [in] to array to multiply
  * @param [in] b scalar to multiply
  * @return array with the multiplication of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename R1> 
Array<T,A_Mult<T,R1,A_Scalar<T>> > operator* (Array<T, R1> const& a, T const& b) 
{ 
    return Array<T,A_Mult<T,R1,A_Scalar<T>> > 
           (A_Mult<T,R1,A_Scalar<T>>(a.rep(), A_Scalar<T>(b))); 
}

/**********************************************************************/ /**
 *
 *  Calculate the power of an array with a scalar
  *
  * @param [in] to array to raise
  * @param [in] b scalar to raise
  * @return array with the power of the elements of a and b
 *
*/ /**********************************************************************/
template <typename T, typename Rep>
Array<T, A_Pow<T, Rep, A_Scalar<T>>> Array<T, Rep>::pow(T const &b) {
    return Array<T, A_Pow<T, Rep, A_Scalar<T>>>(A_Pow<T, Rep, A_Scalar<T>>(rep(), A_Scalar<T>(b)));
}

#endif
