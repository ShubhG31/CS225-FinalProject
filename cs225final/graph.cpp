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
        nodeList.push_back(node);
    }
}

void Graph::makeEdgeList(string file){
    ifstream fin(file, ios::in);

    if (!fin.is_open()) {
        std::cerr << "There was a problem opening the input file!\n";
        exit(1);//exit or do additional error checking
    }

    while (!fin.eof()) {
        int garbage;
        fin >> garbage;
        int firstnode;
        fin>> firstnode;
        int secondnode;
        fin>>secondnode;
        double distance;
        fin >> distance;
        
        vector<pair<int,double> > edges;
        if(edgelist.find(firstnode) != edgelist.end()){
            edges=edgelist[firstnode];
        }
        edges.push_back(make_pair(secondnode,distance));
        edgelist[firstnode] = edges;
        vector<pair<int,double> > temp= edgelist[firstnode];
        // std::cout << temp[0].first << std::endl;

    }
    vector<pair<int,double> > temp= edgelist[0];
    std::cout << temp[0].first << std::endl;
}

// void Graph::addEdge(Node node1, Node node2, double dist) {

// }

// double Graph::dist(double longitude, double latitude) {
//     return -1;
// }

vector<int> Graph::findShortestPath(int first, int second){
    map<int,double> distances;
    map<int,bool> visited;
    map<int,vector<int>>paths;
    auto cmp = [&](pair<int,double> first, pair<int,double> sec){return first.second > sec.second;};
    priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(cmp)> q(cmp);
    q.push(pair<int,double>{first,0});
    visited[first] = true;
    paths[first] = vector<int>();
    while (!q.empty()){
        pair<int,double> top = q.top();
        q.pop();
        auto edges = adjacent(top.first);
        // i.first is the adjacent node and i.second is the edge length(not the distance from the root)
        for(pair<int,double> i : edges){
            if(!visited[i.first]){
                distances[i.first] = distances[top.first] + i.second;
                q.push(i);
                visited[i.first] = true;
                paths[i.first] = paths[top.first];
                paths[i.first].push_back(top.first);
            }
            if(i.first == second){
                return paths[i.first];
            }
        }
    }
    throw runtime_error("not found");
}

vector<pair<int, double>> Graph::adjacent(int node){
    return edgelist[node];
}