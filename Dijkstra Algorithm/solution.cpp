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
        
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty()) {
            auto [dis, node] = *(st.begin());
            st.erase({dis, node});
            
            if(dis > dist[node])
                continue;
                
            for(auto [it, edgeWt] : adj[node]) {
                if(dis + edgeWt < dist[it]) {
                    if(dist[it] != 1e9) {
                        st.erase({dist[it], it});
                    }
                    
                    dist[it] = dis + edgeWt;
                    st.insert({dist[it], it});
                }
            }
        }
        
        return dist;
        
    }
};