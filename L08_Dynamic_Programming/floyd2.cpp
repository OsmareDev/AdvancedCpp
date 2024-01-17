#include <iostream>
#include <random>
#include "graph.h"

constexpr unsigned TAM = 8;

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected = true);

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
CreateConnectionsRand(Graph<T, TAM> &g, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX, bool undirected = true);

void SetInitPath(Graph<int, TAM> &p);

template <typename T>
void SetMatrix(Graph<T, TAM> &g, std::mt19937& gen);

template<typename T>
Graph<T, TAM> Floyd(Graph<T, TAM> g, Graph<int, TAM> &p, bool undirected = true);

template <typename T>
T min (const T &a, const T &b);

void PrintPath(Graph<int, TAM> p, int origen, int destino);

int main()
{
    Graph<float, TAM> g;
    Graph<int, TAM> p;

    bool undirected = false;

    std::random_device rd;
	std::mt19937 gen(rd());
    std::cout << "********** FLOYD 2  **********" << std::endl;

    CreateConnectionsRand(g, gen, 0.5, 5.5, undirected);
    g.Print();
    std::cout << "********************" << std::endl;
    Graph<float, TAM> f = Floyd(g, p, undirected);
    p.Print();
    
    for (unsigned i = 0; i < 2; ++i)
    {
        for (unsigned j = i+1; j < TAM; ++j)
        {
            std::cout << "Path from " << i << " to " << j << ": ";
            PrintPath(p, i, j);
        }
    }

    return 0;
}


/******************************************************************************* */
/*
 * @brief Set the initial path matrix.
 *
 * @param [out] p the path matrix.
 *  
*/ /*******************************************************************************/
void SetInitPath(Graph<int, TAM> &p){
    for (unsigned i = 0; i < TAM; ++i)
        for (unsigned j = 0; j < TAM; ++j)
            p(i, j) = j;
}

/******************************************************************************* */
/*
 * @brief Computes the shortest path between two nodes in a graph using Floyd's algorithm. Also
 *        calculate the path matrix.
 *
 * @param [in] g the graph.
 * @param [in,out] p the path matrix.
 * @param [in] undirected a boolean value indicating whether the graph is undirected or not.
 * 
 * @return the shortest path between two nodes in a graph.
 * 
*/ /*******************************************************************************/

template<typename T>
Graph<T, TAM> Floyd(Graph<T, TAM> g, Graph<int, TAM> &p, bool undirected){
    SetInitPath(p);
    
    for (unsigned k = 0; k < TAM; ++k){
        for ( unsigned i = 0; i < TAM; ++i) {
            for ( unsigned j = 0; j < TAM; ++j) {
                if (g(i, j) > g(i,k)+g(k,j)) {
                    g(i, j) = g(i,k)+g(k,j);
                    p(i, j) = k;
                }
            }
        }
    }

    return g;
}

/******************************************************************************* */
/*
 *  @brief Prints the path from the origin to the destination node in the graph.
 *
 * @param [in] p the path matrix.
 * @param [in] origen the origin node.
 * @param [in] destino the destination node.
 * 
*/ /*******************************************************************************/ 
 
void PrintPath(Graph<int, TAM> p, int origen, int destino)
{
    while (origen != destino)
    {
        std::cout << origen << " -> ";
        // std::cout << " (D: << " << destino << ")" << std::endl;
        origen = p(origen, destino);
        // std::cout << "." << std::endl;
    }

    std::cout << destino << std::endl;
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