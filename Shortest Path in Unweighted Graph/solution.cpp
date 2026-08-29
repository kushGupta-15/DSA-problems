class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(V, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        
        return (dist[dest] != 1e9) ? dist[dest] : -1;
    }
};
