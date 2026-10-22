class Solution {
public:
    string ans = "";

    void expand(string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
 if (ans.size() < right - left - 1) {
            ans = s.substr(left + 1, right - left - 1);
        }
    }
 string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);      
            expand(s, i, i + 1);   
        }
        return ans;
    }
};
