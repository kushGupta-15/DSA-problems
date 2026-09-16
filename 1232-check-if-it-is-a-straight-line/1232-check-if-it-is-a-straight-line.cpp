class Solution {
    double findSlope(pair<int, int> p1, pair<int, int> p2) {
        int x1 = p1.first, x2 = p2.first;
        int y1 = p1.second, y2 = p2.second;

        if(x1 == x2) {
            return DBL_MAX;
        }
        
        return double(y2 - y1) / double(x2 - x1);
    }

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        if (n == 2) {
            return true;
        }

        double slope = findSlope(
            {coordinates[0][0], coordinates[0][1]},
            {coordinates[1][0], coordinates[1][1]}
        );

        for (int i = 2; i < n; i++) {

            double currentSlope = findSlope(
                {coordinates[0][0], coordinates[0][1]},
                {coordinates[i][0], coordinates[i][1]}
            );

            if (currentSlope != slope) {
                return false;
            }
        }

        return true;
    }
};