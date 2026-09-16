class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        int min_el = *min_element(begin(arr), end(arr));
        int max_el = *max_element(begin(arr), end(arr));

        if((max_el - min_el) % (n-1) != 0) {
            return false;
        }

        int d = (max_el-min_el) / (n-1);
        int i = 0;

        while(i < n) {
            int val = arr[i];
            if(val == min_el + i*d) {
                i++;
            } else {
                if((val - min_el) % d != 0) {
                    return false;
                }

                int j = (val - min_el) / d;
                if(val == arr[j]) {
                    return false;
                }

                swap(arr[i], arr[j]);
            }
        }

        return true;
    }
};