class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V, vector<int>());
        
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        vector<vector<int>> result;
        for(int it = 0; it < V; it++) {
            if(!visited[it]) {
                vector<int> component;
                dfs(it, visited, adjList, component);
                result.push_back(component);
            }
            
        }
        
        return result;
    }
    
  private:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for(auto& it : adjList[node]) {
            if(!visited[it]) {
                dfs(it, visited, adjList, component);
            }
        }
    }
};
