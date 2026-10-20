class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int original = image[sr][sc];
        if(original == color) {
            return image;
        }


        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({sr, sc});
        visited[sr][sc] = 1;

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            image[r][c] = color;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == original && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        return image;
    }
};