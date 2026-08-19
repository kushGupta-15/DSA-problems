class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = 2LL * n;

        map<int, set<int>> mp;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row].insert(col);
            }
        }

        for (auto& [row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Check 2,3,4,5
            for (int col = 2; col <= 5; col++) {
                if (seats.count(col)) {
                    left = false;
                }
            }

            // Check 4,5,6,7
            for (int col = 4; col <= 7; col++) {
                if (seats.count(col)) {
                    middle = false;
                }
            }

            // Check 6,7,8,9
            for (int col = 6; col <= 9; col++) {
                if (seats.count(col)) {
                    right = false;
                }
            }

            if (left && right) {
                // 2 groups possible
            }
            else if (left || middle || right) {
                // 1 group possible
                ans--;
            }
            else {
                // 0 groups possible
                ans -= 2;
            }
        }

        return ans;
    }
};