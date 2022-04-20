#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    string node_data = "nodedataset.csv";
    string edge_data = "edgedataset.csv";
    Graph h("nodedataset.csv","edgedataset.csv");

    // Uncomment lines 8-12 to see the nodedataset being parsed
    // h.makeNodeList("nodedataset.csv");

    // for(auto i: h.nodeList){
    //     std::cout<< i.id << " " << i.longitude << " " << i.latitude <<  std::endl;
    // }

    // Uncomment lines 15-20 to see the edgedataset being parsed
    // h.makeEdgeList("edgedataset.csv");
    // for(auto j: h.edgelist){
    //     for(auto i: j.second){
    //         cout<<i.first << " " << i.second <<endl;
    //     }
    // }
    vector<int> path = h.findShortestPath(5,298);
    for(auto i : path){
        std::cout << i << std::endl;
    }
    return 0;
}