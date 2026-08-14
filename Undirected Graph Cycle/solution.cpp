class Solution {
	public:
	bool isCycle(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V, vector<int>());
		
		for (vector<int>& edge : edges) {
			int u = edge[0];
			int v = edge[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		queue<pair<int, int>> q;
		for (int i = 0; i < V; i++) {
			if (visited[i] == true)
				continue;
			
			q.push({i, -1});
			visited[i] = true;
			
			while (!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				
				for (auto it : adj[node]) {
					if (!visited[it]) {
						q.push({it, node});
						visited[it] = true;
					} else if (parent != it) {
						return true;
					}
				}
			}
		}
		
		return false;
	}
};
