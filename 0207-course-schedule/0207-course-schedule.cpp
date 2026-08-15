class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(vector<int> cources : prerequisites) {
            int ai = cources[0];
            int bi = cources[1];
            adj[bi].push_back(ai);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            } 
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int size = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            size++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return (size == numCourses);
    }
};