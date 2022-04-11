#include "graph.h"

void Graph::makeNodeList(string file) {
    ifstream fin(file, ios::in);

    if (!fin.is_open()) {
        std::cerr << "There was a problem opening the input file!\n";
        exit(1);//exit or do additional error checking
    }

    while (!fin.eof()) {
        Node node;
        fin >> node.id;
        fin >> node.longitude;
        fin >> node.latitude;
    }
}

void Graph::makeEdgeList(string file){
    //ifstream fin(file, ios::in);

    // if (!fin.is_open()) {
    //     std::cerr << "There was a problem opening the input file!\n";
    //     exit(1);//exit or do additional error checking
    // }

    // while (!fin.eof()) {
    //     Node node;
    //     fin >> node.id;
    //     fin >> node.longitude;
    //     fin >> node.latitude;
    // }
}

// void Graph::addEdge(Node node1, Node node2, double dist) {

// }

// double Graph::dist(double longitude, double latitude) {
//     return -1;
// }