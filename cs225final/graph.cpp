#include "graph.h"

Graph::Graph(string node_data, string edge_data){
    makeNodeList(node_data);
    makeEdgeList(edge_data);

}
Graph::Graph(string node_data, string edge_data, string file){
    makeNodeList(node_data);
    makeEdgeList(edge_data);
    base->readFromFile(file);
}
bool operator==(Graph::Node a, Graph::Node b){
    return (b.id==a.id) && (b.longitude == a.longitude) && (b.latitude == a.latitude);
}   

void Graph::read(string filename){

    base->readFromFile(filename);
}

void Graph::makeNodeList(string file) {
    ifstream fin(file, ios::in);

    if (!fin.is_open()) {
        std::cerr << "There was a problem opening the input file!\n";
        exit(1);//exit or do additional error checking
    }

    while (!fin.eof()) {
        Graph::Node node;
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

    while (fin.good()) {
        int garbage;
        fin >> garbage;

        int firstnode;
        fin>> firstnode;
        int secondnode;
        fin>>secondnode;
        long double distance;
        fin >> distance;
        
        vector<pair<int,long double> > edges;
        if(edgelist.find(firstnode) != edgelist.end()){
            edges=edgelist[firstnode];
        }
        edges.push_back(make_pair(secondnode,distance));
        edgelist[firstnode] = edges;
        vector<pair<int,long double> > edges2;
        if(edgelist.find(secondnode) != edgelist.end()){
            edges2=edgelist[secondnode];
        }
        edges2.push_back(make_pair(firstnode,distance));
        edgelist[secondnode] = edges2;
        // vector<pair<int,double> > temp= edgelist[firstnode];
        // std::cout << temp[0].first << std::endl;

    }
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
    paths[first] = vector<int>();
    while (!q.empty()){
        pair<int,double> top = q.top();
        if(top.first == second){
            return paths[top.first];
        }
        q.pop();
        visited[top.first] = true;
        auto edges = adjacent(top.first);
        // i.first is the adjacent node and i.second is the edge length(not the distance from the root)
        for(pair<int,double> i : edges){
            // cout << top.first << " adjacent to " << i.first << " at distance " << i.second <<endl;
            if(!visited[i.first]){
                if(distances[top.first] + i.second < distances[i.first] || distances[i.first] == 0){
                    distances[i.first] = distances[top.first] + i.second;
                    q.push(i);
                    paths[i.first] = paths[top.first];
                    paths[i.first].push_back(top.first);
                }
            }
        }
    }
    throw runtime_error("not found");
}

vector<pair<int,long double>> Graph::adjacent(int node){
    return edgelist[node];
}

Image * Graph::draw(vector<Graph::Node> nodes){

    // Node from = nodes[0];
    // long double x = nodes[0].longitude;
    // long double y = nodes[0].latitude;
    // for (size_t i = 1; i < nodes.size(); i++)
    // {
    //     Node to = nodes[i];

    // }
    
        
    return base;
}