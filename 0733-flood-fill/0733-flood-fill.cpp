class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int initialColor = image[sr][sc];

        if(color == initialColor)
            return image;
            
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0,1}};

            for(auto [r, c] : directions) {
                int nr = r + row;
                int nc = c + col;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == initialColor) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }

        }

        return image;
    }
};