#include "graph.h"
#include <cmath>
Graph::Graph(string node_data, string edge_data){
    makeNodeList(node_data);
    makeEdgeList(edge_data);
    height_ = 500;
    width_ = 500;
    base = new Image();
    base->resize(width_,height_);

}
Graph::Graph(string node_data, string edge_data, string file){
    makeNodeList(node_data);
    makeEdgeList(edge_data);
    base = new Image();
    base->readFromFile(file);
    height_ = base->height();
    width_ = base->width();
}

Graph::~Graph(){
    delete base;
}

bool operator==(const Graph::Node& a, const Graph::Node& b){
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
            paths[top.first].push_back(second);
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

    
    Image* to_return = base;
    // to_return->scale(2);
    // unsigned height = to_return->height();
    // unsigned width = to_return->width();
    // double w_ratio = width/10000;
    // double h_ratio = height/10000;
    // Node from = nodes[0];
    // for (size_t i = 1; i < nodes.size(); i++)
    // {
    //     double x = from.longitude * w_ratio;
    //     double y = from.latitude * h_ratio;
    //     Node to = nodes[i];
    //     double a = to.longitude * w_ratio;
    //     double b = to.latitude * h_ratio;
    //     double slope = (b-y)/(a-x);
    //     int diff = (x < a) ? 1 : -1;
    //     if(x == a){
    //         diff = 0;
    //     }
    //     int nd = (y < b) ? 1 : -1;
    //     cout << "hello" <<endl;
    //     while(abs(x) < abs(a)){
    //         cout<< x << ' ' << y <<endl;
    //         cs225::HSLAPixel& pix = to_return->getPixel((unsigned) x, (unsigned) y);
    //         pix.h = 0;
    //         pix.a = 1;
    //         pix.s = 1;
    //         pix.l = 0.5;
    //         x += diff;
    //         if(diff){
    //             y+= slope*(x-a);
    //         }else{
    //             y += nd;
    //         }
    //     }
    //     from = to;
    // }   
    return to_return;
}



vector<Graph::Node> Graph::convert(vector<int> vect){
    vector<Node> to_return;
    for(int i : vect){
        to_return.push_back(nodeList[i]);
    }
    return to_return;
}

Image* Graph::drawBase(){
    double factor_X = (double)width_ / 10000;
    double factor_Y = (double)height_ / 10000;
    for(unsigned x = 0; x < width_; ++x){
        for (unsigned y = 0; y < height_; ++y){
            cs225::HSLAPixel& pix = base->getPixel(x,y);
            pix.h = 0;
            pix.l = 1;
            pix.a = 1;
            pix.s = 0;
        }
    }
    for(Node n : nodeList){
        cs225::HSLAPixel& pix = base->getPixel(round(n.longitude*factor_X),round(n.latitude*factor_Y));
        pix.h = 0;
        pix.l = 0;
        pix.a = 0;
        pix.s = 0;
    }
    return base;
}

