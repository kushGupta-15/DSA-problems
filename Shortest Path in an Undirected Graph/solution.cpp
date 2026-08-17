class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges,
                             int src, int dest) {

        vector<vector<pair<int, int>>> adj(V + 1);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Dijkstra from destination
        vector<int> dist(V + 1, 1e9);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[dest] = 0;
        pq.push({0, dest});

        while(!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            for(auto [next, wt] : adj[node]) {

                if(dis + wt < dist[next]) {
                    dist[next] = dis + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        // No path exists
        if(dist[src] == 1e9)
            return {-1};

        // Construct lexicographically smallest shortest path
        vector<int> path;
        int node = src;

        path.push_back(src);

        while(node != dest) {

            int best = -1;

            // Find smallest neighbor that can still lead
            // to a shortest path
            for(auto [next, wt] : adj[node]) {

                if(dist[node] == wt + dist[next]) {

                    if(best == -1 || next < best) {
                        best = next;
                    }
                }
            }

            node = best;
            path.push_back(node);
        }

        return path;
    }
};