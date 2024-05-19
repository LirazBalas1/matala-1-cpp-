//finish

//Liraz Balas
//211801220
//lbalad13@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {2, 2, 0, 2},
        {0, 0, 2, 0},
        {0, 0, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    CHECK_THROWS(g.loadGraph(graph2));

}


  TEST_CASE("Test isConnected")
{
    ariel::Graph g;


    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isConnected(g)));
    
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g));


    vector<vector<int>> graph3 = {
        {0, 0},
        {1, 0}};
    g.loadGraph(graph3);
    CHECK(!ariel::Algorithms::isConnected(g));

    
    vector<vector<int>> graph4 = {
            {0, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 0, 0}};
    g.loadGraph(graph4);
    CHECK(!ariel::Algorithms::isConnected(g));
    
    
      vector<vector<int>> graph5 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        g.loadGraph(graph5);
     CHECK(ariel::Algorithms::isConnected(g));
    


    vector<vector<int> > graph6 =
      {{0, 0, 0},
       {0, 0, 0},
       {0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(!ariel::Algorithms::isConnected(g));
    
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 3));
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
     CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");

     vector<vector<int>> graph2 = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");


     vector<vector<int>> graph3 = {
        {0, 1, -2},
        {1, 0, 3},
        {-2, 3, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "The graph contains a negative cycle.");


    vector<vector<int>> graph4 = {
        {0, -8, 1},
        {0, 0, -6},
        {0, 0, 0}};

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;

    
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: setA={0, 2}, setB={1}.");


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");
}
TEST_CASE("Test negative cycles"){
    ariel::Graph g;

   
     vector<vector<int>> graph = {
        {0, -1, -2},
        {-1, 0, -3},
        {-2, -3, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

   vector<vector<int>> graph2 = {
        {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}};

    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph not contains negative cycle");
}
TEST_CASE("Test isContainsCycle"){
    ariel::Graph g;

   
    vector<vector<int>> graph = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");


    vector<vector<int>> graph2 = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle in the graph is : 0->2->1->0");

}


