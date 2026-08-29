class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> topo = topoSort(V, edges);
        
        return (topo.size() != V);
    }
    
  private:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V, vector<int>());

        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
        }

        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it : adjList[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adjList[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};