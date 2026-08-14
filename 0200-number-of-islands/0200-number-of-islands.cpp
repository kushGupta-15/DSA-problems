#include<vector>
using namespace std;

class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0' || visited[row][col]) {
            return;
        } 

        vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        visited[row][col] = true;

        for(auto [dr, dc] : directions) {
            dfs(row + dr, col + dc, grid, visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};