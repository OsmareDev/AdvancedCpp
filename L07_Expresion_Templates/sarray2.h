/**
 * Class Simple Array (SArray)
 * 
 */

#ifndef _SARRAY2_H
#define _SARRAY2_H

#include <iostream>
#include <cmath>

template<typename T> 
class SArray2 
{   
    T*     storage;       // storage of the elements 
    size_t storage_size;  // number of elements 

public: 
    // create array with initial size 
    explicit SArray2 (size_t s)
    : storage(new T[s]), storage_size(s) { 
        init(); 
    } 

    // copy constructor 
    SArray2 (SArray2<T> const& orig) 
    : storage(new T[orig.size()]), storage_size(orig.size()) { 
        copy(orig); 
    } 
    
    ~SArray2() { 
        delete[] storage; 
    } 

    SArray2<T>& operator= (SArray2<T> const& orig) { 
        if (&orig != this) { 
            copy(orig); 
        } 
        return *this; 
    } 

    size_t size() const { 
        return storage_size; 
    } 

    T operator[] (size_t idx) const { 
        return storage[idx]; 
    } 
    T& operator[] (size_t idx) { 
        return storage[idx]; 
    }

    SArray2<T> pow(T pot);

    // *** SUM ***
    // Array + Array
    template <typename T2>
    friend SArray2<T2> operator+(SArray2<T2> a, SArray2<T2> const &b);
    // Array + Num
    template <typename T2>
    friend SArray2<T2> operator+(SArray2<T2> a, T2 const &b);

    // Num + Array
    template <typename T2>
    friend SArray2<T2> operator+(T2 const &b, SArray2<T2>  a);

    // *** MULTIPLY ***
    // Array * Array
    template <typename T2>
    friend SArray2<T2> operator*(SArray2<T2> a, SArray2<T2> const &b);
    // Array * Num
    template <typename T2>
    friend SArray2<T2> operator*(SArray2<T2> a, T2 const &b);

    // Num * Array
    template <typename T2>
    friend SArray2<T2> operator*(T2 const &b, SArray2<T2>  a);
    
protected: 
    // init values with default constructor 
    void init() { 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = T(); 
        } 
    } 

    // copy values of another array 
    void copy (SArray2<T> const& orig) { 
        assert(size() == orig.size()); 
        for (size_t idx = 0; idx<size(); ++idx) { 
            storage[idx] = orig.storage[idx]; 
        } 
    } 
};

// *** SUM ***

// Array + Array
template <typename T>
SArray2<T> operator+ (SArray2<T> a, SArray2<T> const& b) {
    assert(b.size() == a.size() && a.size() >= 0);

    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] + b[i];
    }

    return a;
}
// Array + Num
template <typename T>
SArray2<T> operator+ (SArray2<T> a, T const& b) {
    assert(a.size() >= 0);
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] + b;
    }

    return a;
}

// Num + Array
template <typename T>
SArray2<T> operator+ (T const& b, SArray2<T> a) {
    assert(a.size() >= 0);
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] + b;
    }

    return a;
}

// *** MULTIPLY ***

// Array * Array
template <typename T>
SArray2<T> operator* (SArray2<T> a, SArray2<T> const& b) {
    assert(b.size() == a.size() && a.size() >= 0);

    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] * b[i];
    }

    return a;
}
// Array * Num
template <typename T>
SArray2<T> operator* (SArray2<T> a, T const& b) {
    assert(a.size() >= 0);
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] * b;
    }

    return a;
}

// Num * Array
template <typename T>
SArray2<T> operator* (T const& b, SArray2<T> a) {
    assert(a.size() >= 0);
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] * b;
    }

    return a;
}

// Num * Array
template <typename T>
SArray2<T> SArray2<T>::pow(T pot)
{
    SArray2<T> res = SArray2<T>(*this);

    for (size_t i = 0; i < this->size(); ++i)
        res[i] = std::pow(this->storage[i], pot);

    return res;
}

#endif