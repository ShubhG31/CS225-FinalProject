#include "catch/catch.hpp"
#include <string>
#include "graph.h"
#include <iostream>

using namespace std;

long double error = 0.00001;

TEST_CASE("Test hello world", "") {
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<int> sol{0,1,2,3};
  REQUIRE(sol == h.findShortestPath(0,4));
}

TEST_CASE("Node Data Parsing", "") {
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<Graph::Node> sol{Graph::Node{0,-0.5,-0.08},Graph::Node{1,-10,0},Graph::Node{2 ,0, 0},Graph::Node{3, 0 ,0},Graph::Node{4,0 ,0}};
  for(unsigned long i =0; i<sol.size();i++){
    REQUIRE(sol[i].id == h.nodeList[i].id);
    REQUIRE(fabs((long double)sol[i].latitude - (long double)h.nodeList[i].latitude) < error);
    REQUIRE(fabs((long double)sol[i].longitude - (long double)h.nodeList[i].longitude) < error);
  }
}
