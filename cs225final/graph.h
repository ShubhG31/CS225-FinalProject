#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class Graph {

    public:
        struct Node {
        int id;
        double longitude;
        double latitude;
    };

        void makeNodeList(string file);
        void makeEdgeList(string file);
        void addEdge(Node node1, Node node2, double dist);
        double dist(double longitude, double latitude);
    
    private:
        vector<vector<double>> edgeList;
        vector<Node> nodeList;
};