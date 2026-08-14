#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while(!q.empty()) {
            auto [pos, d] = q.front();
            q.pop();

            int row = pos.first;
            int col = pos.second;
            
            dist[row][col] = d;
            for(auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, d+1});
                }
            }
        }

        return dist;
    }
};