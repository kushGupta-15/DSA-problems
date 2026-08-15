class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0), pathVisited(V, 0), check(V, 0), safeNodes;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, visited, pathVisited, check, graph);
            }
        }

        for(int i = 0; i < V; i++) {
            if(check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
private:
    void dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<int>& check, vector<vector<int>>& graph) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : graph[node]) {
            if(!visited[it]) {
                dfs(it, visited, pathVisited, check, graph);
                if(pathVisited[it] == 1)
                    return;
            } else if(pathVisited[it] == 1) {
                return;
            }
        }

        check[node] = 1;
        pathVisited[node] = 0;
    }
};