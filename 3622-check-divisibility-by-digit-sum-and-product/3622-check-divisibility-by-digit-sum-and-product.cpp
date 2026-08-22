class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1;
        int temp = n;

        while(temp > 0) {
            digitSum = digitSum + (temp % 10);
            digitProduct = digitProduct * (temp % 10);

            temp = temp / 10;
            // cout << temp << " " << digitSum << " " << digitProduct << endl;

        }
        
        int sum = digitSum + digitProduct;
        // cout << sum << endl;

        return (n % sum == 0);
    }
};