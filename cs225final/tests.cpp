#include "catch/catch.hpp"
#include <string>
#include "graph.h"

using namespace std;

TEST_CASE("Test hello world", "") {
  string node_data = "node.csv";
  string edge_data = "edge.csv";
  Graph h(node_data, edge_data);
  vector<int> sol{0,1,2,3};
  REQUIRE(sol == h.findShortestPath(0,4));
}