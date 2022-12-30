#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


vector<tuple<int, int, int>> _data; // saves all edges data in the form (w, u, v)
vector<int> _parent;                // saves "parents" of the (index+1) vertex
int _vertices, _edges;              // saves number of vertices / edges
int _weight;                        // saves the sum of weights of the path taken


void parseInput() {
    
    cin >> _vertices;               // read vertices
    cin >> _edges;                  // read edges

    for(int i=0; i<_edges; i++) {   // create data vector

        int w, u, v;
        if(scanf("%d %d %d\n", &u, &v, &w)>0) {}    // avoid unused return value
        _data.push_back(make_tuple(w, u, v));
    }
    _parent.resize(_vertices, 0);

    sort(_data.begin(), _data.end());   // sort the data vector by weight
}

bool notCycle(int u, int v) {

    // same "parents" -> creates cycle
    if ( (_parent[u-1]==_parent[v-1]) && _parent[u-1]!=0 ) return false;

    // both vertices haven't been found
    if (_parent[u-1]==_parent[v-1]) {
        int parent = (u>v)? u : v;
        _parent[u-1] = parent;
        _parent[v-1] = parent;
    }

    // different parents
    else {
        int parent = (_parent[u-1]>_parent[v-1])? _parent[u-1] : _parent[v-1];
        int update = (_parent[u-1]>_parent[v-1])? _parent[v-1] : _parent[u-1];

        // only one vertex was found
        if (update==0) {
            _parent[u-1] = parent;
            _parent[v-1] = parent;
        }

        // both vertices have been found -> join trees
        else {
            for(int i=0; i<_edges; i++) {
                if(_parent[i]==update) _parent[i]=parent;
            }
        }
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