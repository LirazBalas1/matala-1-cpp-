//Liraz Balas
//211801220
//lbalad13@gmail.com

#include "Graph.hpp"

using namespace ariel;


 //This function receives an adjacency matrix and loads it into the graph
 //first we check 2 conditions:
 //-if the graphis not square matrix return  error
 //-if in the diagonal of the adjency matrux we have 0 return 0 
 //if the two condtion pass we update the matrix to be the graph that receive in the function 

void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

    for(unsigned int i = 0; i < graph.size(); i++){
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

		if (graph[i][i] != 0){
			throw invalid_argument("Invalid graph:0 in the diagonal.");
		}
    }
    matrix = graph;
}

// This function returns a string that is a representation of the adjacency matrix.
string Graph::printGraph() const {
    int count_edges = 0;

    for (const auto& i : matrix) {
        for (int j : i) {
            if (j != 0) {
                count_edges++;
            }
        }
    }

    
    string ans = "The Graph conatins  " + std::to_string(matrix.size()) + " vertices and " + to_string(count_edges) + " edges.";
    return ans;
}

//This function return the size of the adjacency matrix:that is the number of vertices in the graph.
unsigned int Graph::size() const{
    return matrix.size();
}

//  This function transposes the graph
void Graph::transpose_graph() {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i + 1; j < matrix.size(); j++) {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

//This function receive two number that correspond to two vertices and return the weight of the edge between this two vertices. 
//If no edge exists,this function returns 0.
const int Graph::getWeight(unsigned int x, unsigned int y) const{

    if (x >= matrix.size() || y >= matrix[0].size()) {
        throw out_of_range("Index out of range");
    }

    return matrix[x][y];
}

//This function receive aumber that coresponds to  the index of the vertex a
//This function return a vector that contains all vertex  connected to the specified vertex that receive in function.
vector<unsigned int> Graph::getVoisin_specificvertix(unsigned int vertex) const {

    vector<unsigned int> voisin_specific_vert;

    if (vertex >= matrix.size()) {
        throw out_of_range("Index out of range");
    }


    const vector<int>& edges = matrix[vertex];
    for (unsigned int i = 0; i < edges.size(); ++i) {
        if (edges[i] != 0) {
            voisin_specific_vert.push_back(i);
        }
    }

    return voisin_specific_vert;
}




