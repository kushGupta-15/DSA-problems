#include<vector>
using namespace std;

class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        for (int it : graph[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                if (!dfs(it, graph, color))
                    return false;
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};