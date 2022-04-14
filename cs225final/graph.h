#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <exception>

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
        vector<int> findShortestPath(int first, int second);
        vector<pair<int,double>> adjacent(int node);
    private:
        map<int, vector<pair<int,double>>> edgelist;
        vector<Node> nodeList;
};