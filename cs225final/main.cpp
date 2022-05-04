#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    string node_data = "sanfrancisco/SF.txt";
    string edge_data = "sanfrancisco/SF2.txt";
    string img = "assets/sanfrancisco.png";
    Graph h(node_data, edge_data);

    // Uncomment lines 8-12 to see the nodedataset being parsed
    //h.makeNodeList("nodedataset.csv");

    // for(auto i: h.nodeList){
    //     std::cout<< i.id << " " << i.longitude << " " << i.latitude <<  std::endl;
    // }

    // Uncomment lines 15-20 to see the edgedataset being parsed
    //h.makeEdgeList("edgedataset.csv");
    // for(auto j: h.edgelist){
    //     for(auto i: j.second){
    //         cout<<i.first << " " << i.second <<endl;
    //     }
    // }
    Image* visual = h.drawBase();
    visual->writeToFile("myfile.png");
    return 0;
}