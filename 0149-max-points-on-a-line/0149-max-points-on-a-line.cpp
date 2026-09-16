class Solution {
    double findSlope(pair<int, int> p1, pair<int, int> p2) {
        int x1 = p1.first, x2 = p2.first;
        int y1 = p1.second, y2 = p2.second;

        return double(y2 - y1) / double(x2 - x1);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
            
        int ans = 0;

        for (int i = 0; i < points.size(); i++) {

            unordered_map<double, int> mp;

            for (int j = i + 1; j < points.size(); j++) {

                if (points[j][0] == points[i][0]) {
                    mp[DBL_MAX]++;
                    ans = max(ans, mp[DBL_MAX] + 1);
                }
                else {
                    double slope = findSlope(
                        {points[i][0], points[i][1]},
                        {points[j][0], points[j][1]}
                    );

                    mp[slope]++;
                    ans = max(ans, mp[slope] + 1);
                }
            }
        }

        return ans;
    }
};