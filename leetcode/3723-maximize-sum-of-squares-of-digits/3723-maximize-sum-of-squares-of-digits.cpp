class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }
        int k = sum / 9;
        int rem = sum % 9;
      string ans(k, '9');
       if (rem > 0) {
            ans += char('0' + rem);
        }
    ans += string(num - ans.size(), '0');
    return ans;
    }
};


