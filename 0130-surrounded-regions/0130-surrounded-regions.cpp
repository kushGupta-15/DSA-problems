#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = true;
            }

            if(board[i][n-1] == 'O' && !visited[i][n-1]) {
                q.push({i, n-1});
                visited[i][n-1] = true;
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
            }

            if(board[m-1][j] == 'O' && !visited[m-1][j]) {
                q.push({m-1, j});
                visited[m-1][j] = true;
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 'O' && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
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