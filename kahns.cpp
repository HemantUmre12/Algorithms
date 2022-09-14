// Kahn's Algorithm to find topological sort using bfs
// Take adjacency list as hash-map
// K is the nodes number from 1 - K
// Returns the topological sort

vector<int> kahnsAlgo(unordered_map<int, vector<int>> &adj, int k) {
  vector<int> inDegree(k + 1), topoSort;
  for(int i = 1; i <= k; i++) {
      if(adj.find(i) != adj.end()) {
          for(auto &next : adj[i]) {
              inDegree[next]++;
          }
      }
  }
  queue<int> q;
  for(int i = 1; i <= k; i++) {
      if(inDegree[i] == 0) {
          q.push(i);
      }
  }
  while(!q.empty()) {
      int node = q.front(); q.pop();
      topoSort.push_back(node);
      for(auto &next : adj[node]) {
          inDegree[next]--;
          if(inDegree[next] == 0) {
              q.push(next);
          }
      }
  }
  return topoSort;
}
