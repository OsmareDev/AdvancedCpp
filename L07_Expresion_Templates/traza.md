# TRAZA SUMA

**operador+**

```cpp
// addition of two Arrays
template <typename T, typename R1, typename R2>
Array<T,A_Add<T,R1,R2> > operator+ (Array<T,R1> const& a, Array<T,R2> const& b)
{
    return Array<T,A_Add<T,R1,R2> >
           (A_Add<T,R1,R2>(a.rep(),b.rep()));
}
```

```cpp
return Array<T, A_Add<T,R1,R2>>(A_Add<T,R1,R2>(a.rep(),b.rep()));
```

@Return: Devuelve un Array de tipo <Double, A*Add> en el \_main_expesion.cpp*

Se llama al constructor Array pasandole la policy de A_Add como parametro para `Rep const& rb` que es el atributo `expr_rep;`

```cpp
Array (Rep const& rb) : expr_rep(rb) {}
```

Para pasar el objeto Rep hay que contruirlo para ello se llama al constructor de la policy `A_Add`

```cpp
(A_Add<T,R1,R2>(a.rep(),b.rep()));
```

desde el main a y b son `Array<Double, SArray<Double>>`

`a.rep()` y `a.rep()` devuelve un `SArray<Double>` por lo que:

```cpp
(A_Add<T,R1,R2>(a.rep(), b.rep()));

// R1 : SArray<Double>
// R2 : SArray<Double>
```

Se llama al contructor de A_Add con los anteriores parametros

```cpp
template <typename T, typename OP1, typename OP2>
class A_Add
{
    typename A_Traits<OP1>::ExprRef op1;    // first operand
    typename A_Traits<OP2>::ExprRef op2;    // second operand
}
```

Se convierte de tipo `SArray<Double>` --> `A_Traits<SArray<Double>>::ExprRef` y se guardan en los atributos `op1` y `op2`

```cpp
// constructor initializes references to operands
A_Add (OP1 const& a, OP2 const& b) : op1(a), op2(b) {}
```

Por tanto ahora

```cpp
op1 = a.rep() = A_Traits<SArray<Double>>::ExprRef;
op2 = b.rep() = A_Traits<SArray<Double>>::ExprRef;
```

`expr_rep` tiene guardado los 2 arrays y cuando se llama a `[]` de la clase array:

```cpp
T operator[] (size_t idx) const {
    assert(idx<size());
    return expr_rep[idx];
}
```

Esta función retorna `expr_rep[idx]` que es:

```cpp
// compute sum when value requested
T operator[] (size_t idx) const {
    return op1[idx] + op2[idx];
}
```

que es lo mismo que `x[idx] + y[idx]`

# DONDE ESTA LA RECURSIVIDAD DE LA METAPROGRAMACIÓN?

Para una operacion cualquiera: `x = x + y;` por ejemplo (desde el main)

Lo que ocurre es que primero se crea un objeto para la operacion `x + y` de tipo `Array<Double, A_Add<Double, SArray<Double>, SArray<Double>>>`

Es decir que tiene guardado los 2 arrays y cuando se llama a `elemento[idx]` se llama a la función `operator[]` de la clase Array que lo que hace es sumar (A_Add)

```cpp
// compute sum when value requested
T operator[] (size_t idx) const {
    return op1[idx] + op2[idx];
}
```

Teniendo este objeto, el resultado de `x + y;` (Array conteniendo el ExprRep de A_Add) toca hacer la asignacion `x = (Array de A_Add);` Para ello se llama al operador de asignacion de la clase Array

```cpp
// assignment operator for arrays of different type
template<typename T2, typename Rep2>
Array& operator= (Array<T2, Rep2> const& b) {
    assert(size() == b.size());
    for (size_t idx = 0; idx < b.size(); ++idx) {
        expr_rep[idx] = b[idx];
    }
    return *this;
}
```

que va guardando en el array de x los elementos de la suma que contiene A_Add `return op1[idx] + op2[idx];`
