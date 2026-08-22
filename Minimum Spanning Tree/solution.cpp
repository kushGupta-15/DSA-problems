class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // adj[node] stores a list of {neighbor, weight} pairs
        vector<vector<pair<int,int>>> adj(V);

        // FIX: structured bindings don't work on vector<int> (dynamic size),
        // so extract u, v, wt by index instead
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt}); // edge u -> v with weight wt
            adj[v].push_back({u, wt}); // undirected: also add v -> u
        }

        // min-heap of {weight, node}, ordered by smallest weight first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, false);

        pq.push({0, 0}); // start MST construction from node 0, with 0 initial cost

        int sum = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            // skip stale entries already locked into the MST
            if(visited[node] == 1)
                continue;

            visited[node] = 1;  // lock this node into the MST
            sum += wt;           // add the cost of the edge that brought us here

            // explore neighbors, push only unvisited ones into the heap
            for(auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWt = neighbor.second;

                if(!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};