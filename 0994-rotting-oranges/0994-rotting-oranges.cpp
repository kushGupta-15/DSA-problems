class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int time = 0;

        while(!q.empty()) {
            auto [dir, t] = q.front();
            q.pop();

            int r = dir.first;
            int c = dir.second;

            time = max(t, time);
            
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 && visited[nr][nc] == 0) {
                    q.push({{nr, nc}, t+1});
                    grid[nr][nc] = 2;
                    visited[nr][nc] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans == 0 ? time : -1;
    }
};