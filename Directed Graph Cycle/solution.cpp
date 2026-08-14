class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V, vector<int>());
        
        for(vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(V, false), pathVisited(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, pathVisited, adj) == true)
                    return true;
            }
        }
        
        return false;
    }
    
  private:
    bool dfs(int node, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>>& adj) {
        visited[node] = true;
        pathVisited[node] = true;
        
        for(auto& it : adj[node]) {
            if(!visited[it]) {
                if(dfs(it, visited, pathVisited, adj) == true)
                    return true;
            } else if(pathVisited[it] == true) {
                return true;
            }
        } 
        
        pathVisited[node] = false;
        return false;
    }
};