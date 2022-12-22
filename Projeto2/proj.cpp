#include <iostream>
#include <vector>

using namespace std;


vector<vector<pair<int, int>>> _weights;    // 1st vector: .size() = max weight
                                            // 2nd vector: .size() = edges with weight index - 1
                                            // pair: .first = u, .second = v
vector<int> _predecessors;  // identify cycles in Kruskal
int _weight = 0;            // sum of the weights of edges taken
int _maxW = 0;              // max edge weight


void parseInput() {
    // read number of vertices and edges
    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    // initialize predecessors vector
    _predecessors.resize(vertices-1);
    for(int i=0; i<(vertices-1); i++) _predecessors[i] = 0;

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

bool notCycle(int u, int v) {

    // same predecessors, creates cycle, do not add
    if ( (_predecessors[u-1]==_predecessors[v-1]) && _predecessors[u-1]!=0 ) return false;

    // both vertices haven't been found, create predecessor
    if (_predecessors[u-1]==_predecessors[v-1]) {
        int predecessor = (u>v)? u : v;
        _predecessors[u-1] = predecessor;
        _predecessors[v-1] = predecessor;
    }

    // different predecessors, does not create cycle
    else {
        int predecessor = (_predecessors[u-1]>_predecessors[v-1])? _predecessors[u-1] : _predecessors[v-1];
        int update = (_predecessors[u-1]>_predecessors[v-1])? _predecessors[v-1] : _predecessors[u-1];

        // update all vertices with predecessor 'update' (join trees)
        for(int i=0; i<(int)_predecessors.size(); i++) {
            if(_predecessors[i]==update) _predecessors[i]=predecessor;
        }
    }

    return true;
}

void evaluateInput() {
    // Kruskal Implementation
    for(int i=(int)_weights.size()-1; i>=0; i--) {         // all edges value buckets
        for(int j=(int)_weights[i].size()-1; j>=0; j--) {  // all edges in 'i' value bucket

            int u = _weights[i][j].first;
            int v = _weights[i][j].second;

            if(notCycle(u,v)) {
                _weight += (i+1);
            }
        }
    }
}

int main() {
    parseInput();       // complexity: O(n)
    evaluateInput();    // complexity: O(n)
    cout << _weight << endl;

    return 0;
}