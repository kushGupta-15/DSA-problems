class Solution {

    void dfs(int node, vector<int>& visited, stack<int>& st,
             vector<vector<pair<int, int>>>& adj) {

        visited[node] = 1;

        for(auto it : adj[node]) {
            int v = it.first;

            if(!visited[v]) {
                dfs(v, visited, st, adj);
            }
        }

        st.push(node);
    }

public:

    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);

        for(auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> visited(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;
        

        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(dist[node] == 1e9)
                continue;

            for(auto it : adj[node]) {

                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }


        return dist;
    }
};