#include "bits/stdc++.h"
using namespace std;

// Prim's Algorithm for finding minimum spannig tree(MST)
// Time Complexity : (N + E)log(N)
// where N is the number of nodes and E is the number of edges

// Returns Minimum Spannin Tree

vector<int> prim(unordered_map<int, vector<pair<int, int>>> &adj, int n) {
    vector<int> parent(n, -1), key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <val, node>
    key[0] = 0;
    pq.push(make_pair(0, 0));

    for(int count = 0; count < n - 1; count++) {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    return parent;
}

int main() {

    // Taking Graph as input
    int N, m;
    cin>>N>>m;
    unordered_map<int, vector<pair<int, int>>> adj; // <node, weight>
    int a, b, wt;

    for(int i = 0; i < m; i++) {
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    vector<int> spanningTree = prim(adj, N);

    // Display Minimum Spanning Tree
    for(int i = 0; i < N; i++) {
        cout<<"Node : "<<i<<" "<<"Parent : "<<spanningTree[i]<<endl;
    }

    return 0;
}