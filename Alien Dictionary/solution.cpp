class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<bool> present(26, false);

        for (string &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        vector<vector<int>> adj(26);
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && s1.size() > s2.size()) {
                return {};
            }
        }

        vector<int> visited(26, 0);
        stack<int> st;

        function<bool(int)> dfs = [&](int node) {
            visited[node] = 1;

            for (int next : adj[node]) {
                if (visited[next] == 1) {
                    return false; // cycle
                }

                if (visited[next] == 0) {
                    if (!dfs(next))
                        return false;
                }
            }

            visited[node] = 2;
            st.push(node);

            return true;
        };

        for (int i = 0; i < 26; i++) {
            if (present[i] && visited[i] == 0) {
                if (!dfs(i))
                    return {};
            }
        }

        string ans;

        while (!st.empty()) {
            ans += char(st.top() + 'a');
            st.pop();
        }

        return ans;
    }
};