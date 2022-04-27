#include "bits/stdc++.h"
using namespace std;

class DisjSet {
    int n;
    vector<int> rank, parent;
 
public:
    DisjSet(int n)
    {
        rank.resize(n);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
 
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    int find(int x)
    {
        if (parent[x] != x) { 
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
 
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y); 
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main() {

    DisjSet dis(5);
    dis.Union(2, 3);
    dis.Union(1, 2);
    cout<<dis.find(2)<<endl;
    cout<<dis.find(1)<<endl;
    cout<<dis.find(3)<<endl;

    return 0;
}