class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        int count = 0;

        for (int i : nums1) {
            mn = min(mn, i);
            if (i % 2 == 1) count++;
        }

        return mn % 2 || count == 0;
    }
};