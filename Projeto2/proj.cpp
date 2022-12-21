#include <iostream>
#include <vector>

using namespace std;


vector<vector<pair<int, int>>> _weights;    // 1st vector: .size() = max weight
                                            // 2nd vector: .size() = edges with weight index - 1
                                            // pair: .first = u, .second = v
vector<bool> _vertices;     // use to mark already reached vertices
int _weight = 0;            // sum of the weights of edges taken
int _maxW = 0;              // max edge weight


void parseInput() {
    // read number of vertices and edges
    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    // initialize vertices vector
    _vertices.resize(vertices-1);
    for(int i=0; i<(vertices-1); i++) _vertices[i] = false;

    // read edges
    for(int i=0; i<edges; i++) {
        int u, v, w;

        cin >> u, cin.ignore(), cin >> v, cin.ignore(), cin >> w;
        if(w>_maxW) {
            _maxW = w;
            _weights.resize(w);
        }

        _weights[w-1].push_back({u, v});
    }
}

bool possible(int u, int v, bool flag) {
    // only one vertex has been visited
    if (flag) if(_vertices[u-1] == _vertices[v-1]) return false;
    // one or none vertices have been visited
    if (!flag) if(_vertices[u-1] & _vertices[v-1]) return false;
    _vertices[u-1] = true;
    _vertices[v-1] = true;
    return true;
}

void readInput() {
    for(int i=(int)_weights.size()-1; i>=0; i--) {         // weight of edge

        for(int j=(int)_weights[i].size()-1; j>=0; j--) {  // edges with i+1 weight
            int u = _weights[i][j].first;
            int v = _weights[i][j].second;
            if(possible(u, v, true)) _weight+=(i+1);
        }
        for(int j=(int)_weights[i].size()-1; j>=0; j--) {  // edges with i+1 weight
            int u = _weights[i][j].first;
            int v = _weights[i][j].second;
            if(possible(u, v, false)) _weight+=(i+1);
        }
    }
}


int main() {
    parseInput();       // complexity: O(n)
    readInput();        // complexity: O(n)
    cout << _weight << endl;

    return 0;
}