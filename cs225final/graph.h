#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <exception>
#include "cs225/PNG.h"
#include "Image.h"

using namespace std;

class Graph {
    public:
        struct Node {
        int id;
        long double longitude;
        long double latitude;
    };
        Graph(string node_data, string edge_data);
        Graph(string node_data, string edge_data, string file);
        void makeNodeList(string file);
        void makeEdgeList(string file);
        void addEdge(Node node1, Node node2, double dist);
        double dist(double longitude, double latitude);
        vector<int> findShortestPath(int first, int second);
        vector<pair<int,long double> > adjacent(int node);
        Image * draw(vector<Node> nodes);
        void read(string filename);
        //move to private once testing is completed
        long double x_inc = 0.05715722810;

        vector<Node> nodeList;
        map<int, vector<pair<int,long double> > > edgelist;
        Image* base;
    private:
        // map<int, vector<pair<int,double>>> edgelist;
        // vector<Node> nodeList;
};
bool operator==(Graph::Node a, Graph::Node b);