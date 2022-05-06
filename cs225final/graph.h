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
        double x_;
        double y_;
        };
        // constructors and destructor
        Graph(string node_data, string edge_data);
        Graph(string node_data, string edge_data, string file);
        ~Graph();
        // load nodes
        void makeNodeList(string file);

        // load edges
        void makeEdgeList(string file);

        //add custom edges
        void addEdge(Node node1, Node node2, double dist);

        //djikstra's algorithm to find shortest from one source node's id to the destination node's id
        vector<int> findShortestPath(int first, int second);

        // get adjacent edges to a given node
        vector<pair<int,long double> > adjacent(int node);

        // draw a path (vector<Node>) to the base image;
        void draw(vector<Node> nodes);

        // read a different base Image
        void read(string filename);

        // converts a path of integers to a path of nodes;
        vector<Node> convert(vector<int> vect);

        // draw all the nodes on the base
        void drawBase();

        // draw connection between two nodes(on the base) with the nodes being coloured as nodeColor and edges as edgeColor
        void drawConnection(Node from, Node to, cs225::HSLAPixel nodeColor, cs225::HSLAPixel edgeColor);

        // write the current map to file
        void writeTo(string file);

        // draws all edges
        void drawAllEdges();

        // setters
        void setHeight(unsigned h);
        void setWidth(unsigned w);

        // zoomIn two nodes if their distance is less than 500 pixels. draws the zoomIn part on the top-right of the image.
        void zoomIn(Node start, Node end);

        //move to private once testing is completed
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

        // used only for testing
        static vector<pair<int,int>> testDrawConnection(Node from, Node to);
        int zoomIn_calls = 0;
        

    private:
        // map<int, vector<pair<int,double>>> edgelist;
        // vector<Node> nodeList;
};
bool operator==(const Graph::Node& a, const Graph::Node& b);