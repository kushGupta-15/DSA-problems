class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<bool> visited(V, false);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                count++;
                bfs(i, visited, isConnected);
            }
        }

        return count;
    }

private:
    void bfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int i = 0; i < isConnected.size(); i++) {
                if(isConnected[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};