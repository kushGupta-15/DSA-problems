#include<vector>
#include<stack>
using namespace std;

class Solution {
    void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adjList) {
        visited[node] = true;

        for(auto it : adjList[node]) {
            if(!visited[it]) {
                dfs(it, visited, st, adjList);
            }
        }

        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V, vector<int>());

        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
        }

        vector<bool> visited(V, false);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, visited, st, adjList);
            }
        }

        vector<int> topo;
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            topo.push_back(node);
        }

        return topo;
    }
};