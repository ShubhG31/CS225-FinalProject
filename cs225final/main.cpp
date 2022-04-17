#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph h;

    // h.makeNodeList("nodedataset.csv");

    // for(auto i: h.edgelist){
    //     std::cout<< i <<std::endl;
    // }
    // cout<< h.nodeList[0].latitude << endl;
    // for (std::pair<std::string, int> element : mapOfWordCount) {
    //     // Accessing KEY from element
    //     std::string word = element.first;
    //     // Accessing VALUE from element.
    //     int count = element.second;
    //     std::cout << word << " :: " << count << std::endl;
    // }
    h.makeEdgeList("nodedataset.csv");
    // std::cout << h.edgelist[0].at() <<std::endl;
    return 0;
}