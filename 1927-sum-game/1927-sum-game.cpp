class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftHalf = 0, rightHalf = 0, leftEmpty = 0, rightEmpty = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') leftEmpty++;
                else leftHalf += (num[i] - '0');
            } else {
                if (num[i] == '?') rightEmpty++;
                else rightHalf += (num[i] - '0');
            }
        }

        int totalQ = leftEmpty + rightEmpty;
        int diff = leftHalf - rightHalf;

        if (totalQ % 2 != 0) return true;

        int target = (rightEmpty - leftEmpty) * 9 / 2;
        return diff != target;
    }
};