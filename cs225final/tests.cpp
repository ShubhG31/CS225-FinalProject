#include "catch/catch.hpp"
#include <string>
#include "graph.h"
#include <iostream>

using namespace std;

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
  cout << h.nodeList[0].id << ' ' << h.nodeList[0].longitude << ' ' << h.nodeList[0].latitude <<endl;
  vector<Graph::Node> sol{Graph::Node{0,-0.5,-0.08},Graph::Node{1,-10,0},Graph::Node{2 ,0, 0},Graph::Node{3, 0 ,0},Graph::Node{4,0 ,0}};
    cout << sol[0].id << endl;
  for(unsigned long i =0; i<sol.size();i++){
    REQUIRE(sol[i].id == h.nodeList[i].id);
    REQUIRE(sol[i].latitude == h.nodeList[i].latitude);
    REQUIRE(sol[i].longitude == h.nodeList[i].longitude);
  }
  // vector<Graph::Node> sol{Graph::Node{0,-0.5,-0.08},Graph::Node{1,-10,0},Graph::Node{2 ,0, 0},Graph::Node{3, 0 ,0},Graph::Node{4,0 ,0}};
  cout << sol[0].id << endl;
  REQUIRE(sol== h.nodeList);
}
