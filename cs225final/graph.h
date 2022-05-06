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
#include "StickerSheet.h"

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
        void drawBase();
        void drawConnection(Node from, Node to, cs225::HSLAPixel nodeColor, cs225::HSLAPixel edgeColor);
        void writeTo(string file);
        void drawAllEdges();
        void setHeight(unsigned h);
        void setWidth(unsigned w);
        void zoomIn(Node start, Node end);

        //move to private once testing is completed
        long double x_inc = 0.05715722810;

        vector<Node> nodeList;
        map<int, vector<pair<int,long double> > > edgelist;
        unsigned width_;
        unsigned height_;
        Image* base;
        StickerSheet * zoomedIn;

        // Colors
        cs225::HSLAPixel yellow = cs225::HSLAPixel(60, 1, .5, 1);
        cs225::HSLAPixel orange = cs225::HSLAPixel(23,.95,.52, 1);
        cs225::HSLAPixel green = cs225::HSLAPixel(120,1,.5, 1);
        cs225::HSLAPixel red = cs225::HSLAPixel(0,1,.5, 1);
        cs225::HSLAPixel black = cs225::HSLAPixel(0, 0, 0, 1);
        cs225::HSLAPixel transparent = cs225::HSLAPixel(0, 0, 0, 0);

    private:
        // map<int, vector<pair<int,double>>> edgelist;
        // vector<Node> nodeList;
};
bool operator==(const Graph::Node& a, const Graph::Node& b);