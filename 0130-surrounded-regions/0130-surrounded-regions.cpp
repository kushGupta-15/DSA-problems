class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O' && visited[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};