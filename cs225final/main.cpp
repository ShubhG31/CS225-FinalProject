#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph h;

    // Uncomment lines 8-12 to see the nodedataset being parsed
    h.makeNodeList("nodedataset.csv");

    for(auto i: h.nodeList){
        std::cout<< i.id << " " << i.longitude << " " << i.latitude <<  std::endl;
    }

    // Uncomment lines 15-20 to see the edgedataset being parsed
    h.makeEdgeList("edgedataset.csv");
    for(auto j: h.edgelist){
        for(auto i: j.second){
            cout<<i.first << " " << i.second <<endl;
        }
    }
    return 0;
}