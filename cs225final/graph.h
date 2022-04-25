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
        long double longitude;
        long double latitude;
    };
        Graph(string node_data, string edge_data);
        void makeNodeList(string file);
        void makeEdgeList(string file);
        void addEdge(Node node1, Node node2, double dist);
        double dist(double longitude, double latitude);
        vector<int> findShortestPath(int first, int second);
        vector<pair<int,long double> > adjacent(int node);
        vector<Node> nodeList;
        map<int, vector<pair<int,long double> > > edgelist;
    private:
        // map<int, vector<pair<int,double>>> edgelist;
        // vector<Node> nodeList;
};
bool operator==(Graph::Node a, Graph::Node b);