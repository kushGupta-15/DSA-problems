class Solution {

    vector<int> topoSort(int V, vector<vector<int>>& adj,
                         vector<bool>& present) {

        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:

    string findOrder(vector<string> &words) {

        int n = words.size();

        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        for(auto &word : words) {
            for(char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for(int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool found = false;

            for(int ptr = 0; ptr < len; ptr++) {

                if(s1[ptr] != s2[ptr]) {

                    int u = s1[ptr] - 'a';
                    int v = s2[ptr] - 'a';

                    adj[u].push_back(v);

                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj, present);

        if(topo.size() != count(present.begin(), present.end(), true)) {
            return "";
        }

        string ans;

        for(auto node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};