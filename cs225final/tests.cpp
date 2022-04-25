#include "catch/catch.hpp"
#include <string>
#include "graph.h"
#include <iostream>

using namespace std;

long double error = 0.00001;

TEST_CASE("Test Shortest Path", "") {
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

TEST_CASE("Edge Data Parsing", ""){
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<pair<int,long double>> r0;
  r0.push_back({1,1});
  vector<pair<int,long double>> r1;
  r1.push_back({2,1});
  vector<pair<int,long double>> r2;
  r2.push_back({3,1});
  vector<pair<int,long double>> r3;
  r3.push_back({4,1});
  vector<pair<int,long double>> r4;
  r4.push_back({0,100});
  map<int, vector<pair<int,long double>>> sol;
  sol[0] = r0;
  sol[1] = r1;
  sol[2] = r2;
  sol[3] = r3;
  sol[4] = r4;
  cout << sol.size() <<endl;
  for(unsigned i =0; i < sol.size();i++){
    for(unsigned j = 0; j < sol.at(i).size(); ++j){
      REQUIRE(sol.at(i).at(j).first == h.edgelist.at(i).at(j).first);
      REQUIRE(sol.at(i).at(j).second == h.edgelist.at(i).at(j).second);
    }
  }
}
