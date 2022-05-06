#include "../cs225/catch/catch.hpp"
#include <string>
#include "../graph.h"
#include <iostream>

using namespace std;

long double error = 0.00001;

TEST_CASE("Test Shortest Path", "djikstra") {
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<int> sol{0,1,2,3,4};
  REQUIRE(sol == h.findShortestPath(0,4));

  node_data = "CSV_tests/node2.csv";
  edge_data = "CSV_tests/edge3.csv";
  Graph h2(node_data, edge_data);
  vector<int> sol2{0,4};
  REQUIRE(sol2 == h2.findShortestPath(0,4));
}
TEST_CASE("Node Data Parsing", "") {
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<Graph::Node> sol{Graph::Node{0,-0.5,-0.08},Graph::Node{1,-10,0},Graph::Node{2 ,0, 0},Graph::Node{3, 0 ,0},Graph::Node{4,0 ,0}};
  for(unsigned long i =0; i<sol.size();i++){
    REQUIRE(sol[i].id == h.nodeList[i].id);
    REQUIRE(fabs((long double)sol[i].y_ - (long double)h.nodeList[i].y_) < error);
    REQUIRE(fabs((long double)sol[i].x_ - (long double)h.nodeList[i].x_) < error);
  }

  node_data = "CSV_tests/node4.csv";
  edge_data = "CSV_tests/edge3.csv";
  Graph h2(node_data, edge_data);
  vector<Graph::Node> sol2{Graph::Node{0,0.5,1},Graph::Node{1,2,0.98},Graph::Node{2 ,1.9, 2.7},Graph::Node{3, 4 ,0.5},Graph::Node{4,6 ,6}, Graph::Node{5, 0, 0}};
  for(unsigned long i =0; i<sol.size();i++){
    REQUIRE(sol2[i].id == h2.nodeList[i].id);
    REQUIRE(sol2[i].y_ == h2.nodeList[i].y_);
    REQUIRE(sol2[i].x_ == h2.nodeList[i].x_);
  }
}

TEST_CASE("Edge Data Parsing", ""){
  string node_data = "CSV_tests/node.csv";
  string edge_data = "CSV_tests/edge.csv";
  Graph h(node_data, edge_data);
  vector<pair<int,long double>> r0;
  r0.push_back({1,1});
  r0.push_back({4,100});
  vector<pair<int,long double>> r1;
  r1.push_back({0,1});
  r1.push_back({2,1});
  vector<pair<int,long double>> r2;
  r2.push_back({1,1});
  r2.push_back({3,1});
  vector<pair<int,long double>> r3;
  r3.push_back({2,1});
  r3.push_back({4,1});
  vector<pair<int,long double>> r4;
  r4.push_back({3,1});
  r4.push_back({0,100});
  map<int, vector<pair<int,long double>>> sol;
  sol[0] = r0;
  sol[1] = r1;
  sol[2] = r2;
  sol[3] = r3;
  sol[4] = r4;

  for(unsigned i =0; i < sol.size();i++){
    for(unsigned j = 0; j < sol.at(i).size(); ++j){
      REQUIRE(sol.at(i).at(j).first == h.edgelist.at(i).at(j).first);
      REQUIRE(sol.at(i).at(j).second == h.edgelist.at(i).at(j).second);
    }
  }
}

TEST_CASE("drawConnection slope up lesseq 1", ""){
  // sloping upwards and slope <= 1
  Graph::Node from {0, 3, 4};
  Graph::Node to {1, 16, 9};
  vector<pair<int,int>> sol{{4,4}, {5,5}, {6,5}, {7,6},{8,6},{9,6},{10,7},{11,7}, {12,7}, {13,8}, {14,8}};
  vector<pair<int,int>> t = Graph::testDrawConnection(from,to);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }

  //order doesn't matter
  t = Graph::testDrawConnection(to,from);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }
}

TEST_CASE("drawConnection slope downward greatereq -1", ""){
  //sloping downward and abs(slope) <= 1
  Graph::Node from {0,5,10};
  Graph::Node to {1,12,8};
  vector<pair<int,int>> sol{{6,10},{7,9},{8,9},{9,9},{10,9},{11,8}};
  vector<pair<int,int>> t = Graph::testDrawConnection(from,to);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }
  
  //order doesn't matter
  t = Graph::testDrawConnection(to,from);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }
}
TEST_CASE("drawConnection slope up greater than 1", ""){
  //sloping upwards and slope > 1
  Graph::Node from {0,4,4};
  Graph::Node to {1,8,12};
  vector<pair<int,int>> sol{{5,5},{5,6},{6,7},{6,8},{7,9},{7,10},{8,11}};
  vector<pair<int,int>> t = Graph::testDrawConnection(from,to);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }

  //order doesn't matter
  t = Graph::testDrawConnection(to,from);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }
}

TEST_CASE("drawConnection slope downward less than -1", ""){
  // sloping upwards and slope <= 1
  Graph::Node from {0, 0, 7};
  Graph::Node to {1, 1, 1};
  vector<pair<int,int>> sol{{1,2}, {1,3}, {0,4}, {0,5},{0,6}};
  vector<pair<int,int>> t = Graph::testDrawConnection(from,to);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }

  //order doesn't matter
  t = Graph::testDrawConnection(to,from);
  for(size_t i = 0; i <sol.size(); ++i){
    REQUIRE(sol.at(i).first == t.at(i).first);
    REQUIRE(sol.at(i).second == t.at(i).second);
  }
}