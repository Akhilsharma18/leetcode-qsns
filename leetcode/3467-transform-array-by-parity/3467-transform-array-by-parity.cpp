class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;
     for (int x : nums)
            ans.push_back(x % 2);
    int i = 0, j = ans.size() - 1;
   while (i < j) {
        while (i < j && ans[i] == 0) i++;
         while (i < j && ans[j] == 1) j--;
           if (i < j)
             swap(ans[i], ans[j]);
        }
     return ans;
    }
};