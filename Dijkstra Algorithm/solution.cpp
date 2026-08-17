class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            
            if(dis > dist[node])
                continue;
                
            for(auto [it, edgeWt] : adj[node]) {
                if(dis + edgeWt < dist[it]) {
                    dist[it] = dis + edgeWt;
                    pq.push({dist[it], it});
                }
            }
        }
        
        return dist;
        
    }
};