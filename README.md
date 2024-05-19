This project implements various graph algorithms using C++. 

The files in the project are:

•	Graph.cpp: This class is the implementation of the Graph class It includes methods to load a graph from an adjacency matrix and to print the graph.

•	Graph.hpp: The header file for Graph.cpp

•	Algorithms.cpp: Implements the graph algorithms : strong connectivity, finding shortest paths, detecting cycles, checking bipartiteness, and identifying negative cycles in a graph.

•	Algorithms.hpp: The header file for Algorithms.cpp, contains the declaration of the ariel namespace, the Algorithms class and its data members.

Grapp.cpp:
1.	graph: An adjacency matrix (2-dimensional vector int array) representing the graph
2.	loadgraph: This function receives an adjacency matrix and loads it into the graph
3.	printGraph: This function returns a string that is a representation of the adjacency matrix.
4.	Size: This function return the size of the adjacency matrix:that is the number of vertices in the graph.
5.	Transpose_graph: This function transposes the graph
6.	getWeight: This function receive two number that correspond to two vertices and return the weight of the edge between this two vertices.If no edge exists,this function returns 0.
7.	getVoisin_sepcificVertex:This function receive aumber that coresponds to  the index of the vertex a This function return a vector that contains all vertex  connected to the specified vertex that receive in function.

Algorithms.cpp
The algorithms treat all :directed undirected ,weighted and unweighted graph
1.	isConnected(g): This function checks if the graph is strongly connected.This returns true or false.We use the algortithm DFS
2.	shortestPath: This functionfinds the shortest path between two vertices .We use the algorithm of  Bellman-Ford algorithm.
3.	isContainsCycle: This function check if  the graph contains cycle.we use the function DFS
4.	isBipartite: This function check if the graph is bipartite.we usethe algorithm BFS
5.	negativeCycle: check is negative cycle in the graph
