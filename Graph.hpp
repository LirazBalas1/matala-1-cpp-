//Liraz Balas
//211801220
//lbalad13@gmail.com
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph{
        vector<vector<int>> matrix; // represent graph by adjency matrix

    public:
        /**
         * This function receives an adjacency matrix and loads it into the graph
         */
        void loadGraph(const vector<vector<int>>& graph);

        /**
         * This function returns a string that is a representation of the adjacency matrix.
         */
        string printGraph() const;


        /**
         * This function return the size of the adjacency matrix:that is the number of vertices in the graph.
         */
        unsigned int size() const;

        /**
         * This function transposes the graph 
         */
        void transpose_graph();

        /**
         *This function receive two number that correspond to two vertices and return the weight of the edge between this two vertices. 
         *If no edge exists,this function returns 0.
         */
        const int getWeight(unsigned int x, unsigned int y) const;

        /**
         * This function receive aumber that coresponds to  the index of the vertex a
         * This function return a vector that contains all vertex  connected to the specified vertex that receive in function.
         */
        vector<unsigned int> getVoisin_specificvertix(unsigned int vertex) const;

        
    };
}