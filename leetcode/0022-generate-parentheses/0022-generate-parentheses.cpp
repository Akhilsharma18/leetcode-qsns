class Solution {
public:
    void solve(vector<string> &ans, string curr, int open, int close, int n) {
      if(curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }
   if(open < n) {
            solve(ans, curr + "(", open + 1, close, n);
        }
  if(close < open) {
            solve(ans, curr + ")", open, close + 1, n);
        }
    }
vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};
