class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList(V, vector<int>());
        
        for(auto& [u, v] : edges) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        return adjList;
        
    }
};