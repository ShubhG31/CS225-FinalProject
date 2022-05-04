#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
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
        ~Graph();
        void makeNodeList(string file);
        void makeEdgeList(string file);
        void addEdge(Node node1, Node node2, double dist);
        double dist(double longitude, double latitude);
        vector<int> findShortestPath(int first, int second);
        vector<pair<int,long double> > adjacent(int node);
        Image * draw(vector<Node> nodes);
        void read(string filename);
        vector<Node> convert(vector<int> vect);
        Image* drawBase();

        //move to private once testing is completed
        long double x_inc = 0.05715722810;

        vector<Node> nodeList;
        map<int, vector<pair<int,long double> > > edgelist;
        unsigned width_;
        unsigned height_;
        Image* base;
    private:
        // map<int, vector<pair<int,double>>> edgelist;
        // vector<Node> nodeList;
};
bool operator==(const Graph::Node& a, const Graph::Node& b);