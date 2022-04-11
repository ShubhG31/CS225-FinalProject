#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

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
        unordered_map<std::pair<int, int>,double> edgelist;
        vector<Node> nodeList;
};