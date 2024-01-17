#include <iostream>
#include <random>
#include <type_traits>
#include "graph.h"

constexpr unsigned TAM = 6;

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected = true);

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected = true);

template <typename T, typename GenT>
void SetMatrix(Graph<T, TAM> &g, std::mt19937 &gen, GenT d, bool undirected);

template<typename T>
Graph<T, TAM> Floyd(Graph<T, TAM> g);

template <typename T>
T min (const T &a, const T &b);

int main()
{
    Graph<float, TAM> g;

    std::random_device rd;
	std::mt19937 gen(rd());

    std::cout << "********************" << std::endl;
    CreateConnectionsRand(g, gen, 0.5, 5.5);
    g.Print();
    std::cout << "********************" << std::endl;
    Graph<float, TAM> f = Floyd(g);
    f.Print();

    return 0;
}


/******************************************************************************* */
/*
 * @brief Computes the shortest path between two nodes in a graph using Floyd's algorithm.
 *
 * @param [in] g the graph.
 * @param [in,out] p the path matrix.
 * @param [in] undirected a boolean value indicating whether the graph is undirected or not.
 * 
 * @return the shortest path between two nodes in a graph.
 * 
*/ /*******************************************************************************/
template<typename T>
Graph<T, TAM> Floyd(Graph<T, TAM> g){
    for (unsigned k = 0; k < TAM; ++k){
        for ( unsigned i = 0; i < TAM; ++i) {
            for ( unsigned j = 0; j < TAM; ++j) {
                g(i, j) = min(g(i, j), g(i,k)+g(k,j));
            }
        }
    }

    return g;
}


/******************************************************************************* */
/*
 *   @brief Return the minimum of two values.
 *
 *   @tparam T the type of the values to compare.
 *
 *   @param [in] a the first value.
 *   @param [in] b the second value.
 *
 *   @return the minimum of the two values.
 *
*/ /*******************************************************************************/
template <typename T>
T min (const T &a, const T &b) {
    return (a < b) ? a : b;
}

/******************************************************************************* */
/*
 *   @brief Generates random edges between nodes in a graph, where the type of the edge weights is either an integral or floating point type.

 *   @tparam T the type of the edge weights in the graph.

 *   @param [in,out] g the graph object.
 *   @param [in] gen the random number generator object.
 *   @param [in] KEY_MIN the minimum edge weight.
 *   @param [in] KEY_MAX the maximum edge weight.
 *   @param [in] undirected a boolean value indicating whether the graph is undirected or not.
 * 
 *   @note This function is enabled only if T is an integral or floating point type.
*/ /*******************************************************************************/
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected) {
    std::uniform_int_distribution<T> dist(KEY_MIN, KEY_MAX);
    // Generate random connections using the uniform integer distribution
    SetMatrix(g, gen, dist, undirected);
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected) {
    std::uniform_real_distribution<T> dist(KEY_MIN, KEY_MAX);
    // Generate random connections using the uniform real distribution
    SetMatrix(g, gen, dist, undirected);
}

/******************************************************************************* */
/*
 *   @brief Generates random edges between nodes in a graph, where the type of the edge weights is either an integral or floating point type.

 *   @tparam T the type of the edge weights in the graph.

 *   @param [in,out] g the graph object.
 *   @param [in] gen the random number generator object.
 *   @param [in] d the distribution object.
 *   @param [in] undirected a boolean value indicating whether the graph is undirected or not.
 * 
*/ /*******************************************************************************/
template <typename T, typename GenT>
void SetMatrix(Graph<T, TAM> &g, std::mt19937& gen, GenT d, bool undirected)
{
    std::uniform_int_distribution<> dist(0, 1);

    if (undirected)
        for (unsigned i = 0; i < TAM; ++i)
        {
            for (unsigned j = i+1; j < TAM; ++j)
            {
                if (i == j)
                    continue;

                g(i,j) = d(gen); 

                if (dist(gen))
                    g(i,j) = g(i,j) * 5;
                
                g(j,i) = g(i,j); 
            }
        }
    else
        for (unsigned i = 0; i < TAM; ++i)
        {
            for (unsigned j = 0; j < TAM; ++j)
            {
                if (i == j)
                    continue;

                g(i, j) = d(gen);

                if (dist(gen))
                    g(i,j) = g(i,j) * 5;
            }
        }
}