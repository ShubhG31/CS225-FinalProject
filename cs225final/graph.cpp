#include "graph.h"
#include <cmath>
#include <limits>
Graph::Graph(string node_data, string edge_data){
    makeNodeList(node_data);
    makeEdgeList(edge_data);
    height_ = 2000;
    width_ = 2000;
    base = new Image();
    base->resize(width_,height_);
    zoomedIn = new StickerSheet(*base, 1);
    for(unsigned x = 0; x < width_; ++x){
        for (unsigned y = 0; y < height_; ++y){
            cs225::HSLAPixel& pix = base->getPixel(x,y);
            pix.h = 0;
            pix.l = 1;
            pix.a = 1;
            pix.s = 0;
        }
    }

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
    // delete base;
    delete zoomedIn;
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
    for(auto i : nodeList){
        distances[i.id] = numeric_limits<double>::max();
    }
    distances[first] = 0;
    auto cmp = [&](pair<int,double> first, pair<int,double> sec){return distances[first.first] > distances[sec.first];};
    priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(cmp)> q(cmp);
    q.push(pair<int,double>{first,0});
    paths[first] = vector<int>();
    while (!q.empty()){

        pair<int,double> top = q.top();

        if(top.first == second){
            cout << distances[top.first]<<endl;
            paths[top.first].push_back(second);
            return paths[top.first];
        }
        q.pop();
        visited[top.first] = true;
        auto edges = adjacent(top.first);
        // i.first is the adjacent node and i.second is the edge length(not the distance from the root)
        for(pair<int,double> i : edges){
            // cout << top.first << " adjacent to " << i.first << " at distance " << i.second <<endl;
                if(distances[top.first] + i.second < distances[i.first]){
                    distances[i.first] = distances[top.first] + i.second;
                    if(!visited[i.first]){
                        q.push(i);
                    }
                    paths[i.first] = paths[top.first];
                    paths[i.first].push_back(top.first);
                }
            
        }
    }
    throw runtime_error("not found");
}

vector<pair<int,long double>> Graph::adjacent(int node){
    return edgelist[node];
}

Image * Graph::draw(vector<Graph::Node> nodes){

    Node from = nodes[0];
    double distance = 0;
    for (size_t i = 1; i < nodes.size(); i++)
    {
        
        Node to = nodes[i];
        cout << to.id << from.id <<endl;
        for(auto j : edgelist.at(from.id)){
            if(j.first == to.id){
                distance += j.second;
                break;
            }
        }
        drawConnection(from,to);
        from = to;
    }
    if(distance < 500){
        zoomIn(nodes[0], nodes[nodes.size()-1]);        
    }   
    
    return base;
}



vector<Graph::Node> Graph::convert(vector<int> vect){
    vector<Node> to_return;
    for(int i : vect){
        to_return.push_back(nodeList[i]);
    }
    return to_return;
}

void Graph::drawBase(){
    double factor_X = (double)(width_ - 1)/ 10000;
    double factor_Y = (double)(height_ - 1) / 10000;
    for(Node n : nodeList){
        unsigned x = round(n.longitude*factor_X);
        unsigned y = round(n.latitude*factor_Y);
        for (unsigned i = x; i <= min(x+1,width_-1); i++)
        {
            for(unsigned j = y; j <= min(y+1,height_-1); ++j){

                cs225::HSLAPixel& pix = base->getPixel(i,j);
                pix.h = 0;
                pix.l = 0;
                pix.a = 1;
                pix.s = 0;
            }
        }
        
    }
}

void Graph::writeTo(string file){
    Image result = zoomedIn->render();
    result.writeToFile(file);
}

void Graph::drawConnection(Node from, Node to) {
    
    cs225::HSLAPixel green (120,1,.5, 1);
    cs225::HSLAPixel red (0,1,.5, 1);


    double factor_X = (double)(width_-1) / 10000;
    double factor_Y = (double)(height_ -1) / 10000;

    int y1 = round(from.latitude * factor_Y); 
    int x1 = round(from.longitude * factor_X); 
    int y2 = round(to.latitude * factor_Y); 
    int x2 = round(to.longitude * factor_X); 
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x;
    int y;
    // cout << dy << ", " << dx << endl;
    if (abs(dy) > abs(dx)) {
        int i1 = 2 * abs(dx);
        int i2 = i1 - 2 * abs(dy);

        int d = i1 - abs(dy);
        x = y1 < y2 ? x1 : x2;
        y = min(y1,y2);

        while (y < max(y1,y2)) {
            y++;
            if (d < 0) {
                base->getPixel(x, y) = green;
                d += i1;
            } else {
                if (dy/dx >= 0) {
                    x++;
                    base->getPixel(x, y) = green;
                    d += i2;
                } else {
                    x--;
                    base->getPixel(x, y) = green;
                    d += i2;
                }
            }
            // cout << i1 << ", " << i2 << ", " << d << endl;
        }
    } else if (abs(dy) < abs(dx)) {
        // cout << dy << ' '<< dx <<endl;
        int i1 = 2 * abs(dy);
        
        int i2 = i1 - 2 * abs(dx);

        int d = i1 - abs(dx);
        y = x1 < x2 ? y1 : y2;
        x = min(x1,x2);

        while (x < max(x1,x2)) {
            x++;
            if (d < 0) {
                base->getPixel(x, y) = green;
                d += i1;
            } else {
                if ((double)dy/dx > 0) {
                    // cout << dy/dx<< endl;
                    y++;
                    base->getPixel(x, y) = green;
                    d += i2;
                } else {
                    y--;
                    base->getPixel(x, y) = green;
                    d += i2;
                }
            }
        }
    } else {
        x = x1;
        y = y1;

        while (x <= x2) {
            // cout << __LINE__ << endl;
            base->getPixel(x, y) = green;
            x++;
            y++;
        }
    }
    base->getPixel(x1, y1) = red;
    base->getPixel(x2, y2) = red;
}

void Graph::drawAllEdges(){
    map<int,bool> seen;
    for(auto i : edgelist){
        seen[i.first] = true;
        for(auto j : i.second){
            if(!(seen[j.first]) || !(seen[i.first])){
                drawConnection(nodeList[i.first],nodeList[j.first]);
                seen[j.first] = true;
            }
        }
    }
}

void Graph::setHeight(unsigned h){
    height_ = h;
}

void Graph::setWidth(unsigned w){
    width_ = w;
}

void Graph::zoomIn(Graph::Node start , Graph::Node end){
    double factor_X = (double)(width_ - 1) / 10000;
    double factor_Y = (double)(height_ -1)/ 10000;

    int y1 = round(start.latitude * factor_Y); 
    int x1 = round(start.longitude * factor_X); 
    int y2 = round(end.latitude * factor_Y); 
    int x2 = round(end.longitude * factor_X); 
    unsigned min_x = min(x1, x2);
    unsigned max_x = max(x1, x2);
    unsigned min_y = min(y1, y2);
    unsigned max_y = max(y1,y2);
    unsigned box_x_start = min_x >= 15 ?min_x - 15 : 0;
    unsigned box_y_start = min_y >= 15 ? min_y - 15 : 0;
    unsigned box_x_end = max_x < width_ - 15 ? max_x + 15 : width_ - 1;
    unsigned box_y_end = max_y < height_ - 15 ? max_y + 15 : height_ - 1;
    unsigned box_width = box_x_end - box_x_start;
    unsigned box_height = box_y_end - box_y_start;
    unsigned x = width_ - box_width;
    unsigned y = 0;
    Image * box = new Image();
    box->resize(box_width, box_height);
    
    cout << box_x_start <<", " << box_x_end << endl;
    cout << box_y_start <<", " << box_y_end << endl;
    unsigned x_box = 0;
    unsigned y_box = 0;
    for(unsigned temp1 = box_x_start ;temp1 < box_x_end; ++temp1){
        y_box = 0;
        for(unsigned temp2 = box_y_start ;temp2 < box_y_end; ++temp2){
            box->getPixel(x_box,y_box) = base->getPixel(temp1, temp2);
            y_box++;
        }
        x_box++;
    }

    box->scale(450,450);
    cout<<"here" <<endl;
    
    zoomedIn->addSticker(*box, width_ - 450, 0);

    // Coord of Nodes in the zoom
    
    
}