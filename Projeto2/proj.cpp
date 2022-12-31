#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


vector<tuple<int, int, int>> _data; // saves all edges data in the form (w, u, v)
vector<pair<int, vector<int>>> _parent;     // saves "parent" of the (index+1) vertex and children
int _vertices, _edges;              // saves number of vertices / edges
int _weight;                        // saves the sum of weights of the path taken


void parseInput() {
    
    ios::sync_with_stdio(false);    // faster read speeds
    cin >> _vertices;               // read vertices
    cin >> _edges;                  // read edges

    for(int i=0; i<_edges; i++) {   // create data vector

        int w, u, v;
        cin >> u, cin.ignore(), cin >> v, cin.ignore(), cin >> w;
        _data.push_back(make_tuple(w, u, v));
    }
    
    for(int i=0; i<_vertices; i++) {    // create _parent vector
        // each vertex has itself has his own "parent" and "child"
        _parent.push_back(make_pair(i+1, vector<int>(1, i+1)));
    }

    sort(_data.begin(), _data.end());   // sort the data vector by weight
}

bool notCycle(int u, int v) {

    // get "parents" of vertex u and v
    int pU = _parent[u-1].first, pV = _parent[v-1].first;

    // same parents -> is a cycle
    if(pU==pV) return false;

    // join tree v with tree u
    if(pU>pV) {

        // update u "children"
        for(int i=0; i<(int)_parent[v-1].second.size(); i++) {
            int vertex = _parent[v-1].second[i];
            _parent[vertex-1].first = pU;
            _parent[u-1].second.push_back(vertex);
        }

        // clear v "children" -> all passed to u
        _parent[v-1].second.resize(0);
        _parent[v-1].second.push_back(v);
    } 
    // join tree u with tree v
    else {

        // update v "children"
        for(int i=0; i<(int)_parent[u-1].second.size(); i++) {
            int vertex = _parent[u-1].second[i];
            _parent[vertex-1].first = pV;
            _parent[v-1].second.push_back(vertex);
        }

        // clear v "children" -> all passed to u
        _parent[u-1].second.resize(0);
        _parent[u-1].second.push_back(u);
    }

    return true;
}

void evaluateInput() {

    // Kruskal Implementation
    for(int i=(_edges-1); i>=0; i--) {
        
        int u = get<1>(_data[i]);
        int v = get<2>(_data[i]);
        
        if(notCycle(u,v)) {
            _weight += get<0>(_data[i]);
        }
    }
}

int main() {

    parseInput();
    evaluateInput();
    cout << _weight << endl;

    return 0;
}