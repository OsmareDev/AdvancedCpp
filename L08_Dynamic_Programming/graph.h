#include <cassert>
#include <limits>

template <typename T, size_t SIZE>
class Graph {
    // Matrix of adjacency directional
    /*
            A   B   C
        A   0   1   3
        B   3   0   5
        C  INF  4   0
    */

    // Matrix of adjacency bidirectional (no need to store the same value twice)
    /*
            A   B   C
        A   0   1  INF
        B       0   3
        C           0
    */

    T m[SIZE][SIZE];

    public:
        Graph();
        T& operator()(size_t origin, size_t dest);
        const T& operator()(size_t origin, size_t dest) const;
        void Print();
};

template <typename T, const size_t SIZE>
Graph<T, SIZE>::Graph() {}

/************************************************************* */
/*
 * @brief Overload of the operator() to access the matrix.
 *
 * @param [in] origin the origin node.
 * @param [in] dest the destination node.
 * 
 * @return the weight of the edge between the origin and destination nodes.
 * 
*/ /************************************************************* */
template <typename T, const size_t SIZE>
T& Graph<T, SIZE>::operator()(size_t origin, size_t dest) { 
    assert(origin < SIZE && dest < SIZE);

    return m[origin][dest];
} 

/************************************************************* */
/*
 * @brief Overload of the operator() to access the matrix.
 *
 * @param [in] origin the origin node.
 * @param [in] dest the destination node.
 * 
 * @return the weight of the edge between the origin and destination nodes.
 * 
*/ /************************************************************* */
template <typename T, const size_t SIZE>
const T& Graph<T, SIZE>::operator()(size_t origin, size_t dest) const { 
    assert(origin < SIZE && dest < SIZE);

    return m[origin][dest];
} 

/************************************************************* */
/*
 * @brief Prints the graph.
 * 
*/ /************************************************************* */
template <typename T, const size_t SIZE>
void Graph<T, SIZE>::Print()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}