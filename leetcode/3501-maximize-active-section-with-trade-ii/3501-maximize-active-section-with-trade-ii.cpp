class SegmentTree {
public:
    int n;
    vector<int> arr, seg;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        if (n == 0) return;
        seg.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    int internalQuery(int node, int st, int en, int l, int r) {
        if (l <= st && en <= r) return seg[node];

        int mid = (st + en) >> 1;
        int res = 0;

        if (mid >= l)
            res = max(res, internalQuery(node * 2, st, mid, l, r));

        if (r > mid)
            res = max(res, internalQuery(node * 2 + 1, mid + 1, en, l, r));

        return res;
    }

    int query(int l, int r) {
        if (l > r || n == 0) return 0;
        return internalQuery(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int segSize = 0;

    int lowerBound(vector<int>& zeroRight, int l) {
        int left = 0, right = segSize;

        while (left < right) {
            int mid = (left + right) >> 1;

            if (zeroRight[mid] >= l)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    int upperBound(vector<int>& zeroLeft, int r) {
        int left = 0, right = segSize;

        while (left < right) {
            int mid = (left + right) >> 1;

            if (zeroLeft[mid] <= r)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();

        int cnt1 = 0;
        for (char c : s)
            if (c == '1')
                cnt1++;

        vector<int> zeroBlocks;
        vector<int> zeroLeft;
        vector<int> zeroRight;

        int idx = 0;

        while (idx < n) {
            int r = idx;

            while (r < n && s[idx] == s[r])
                r++;

            if (s[idx] == '0') {
                zeroBlocks.push_back(r - idx);
                zeroLeft.push_back(idx);
                zeroRight.push_back(r - 1);
            }

            idx = r;
        }

        int m = zeroBlocks.size();
        segSize = m;

        vector<int> ans;

        if (m <= 1) {
            while (ans.size() < queries.size())
                ans.push_back(cnt1);
            return ans;
        }

        vector<int> nums(m - 1);

        for (int i = 0; i < m - 1; i++)
            nums[i] = zeroBlocks[i] + zeroBlocks[i + 1];

        SegmentTree st(nums);

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int l_idx = lowerBound(zeroRight, l);
            int r_idx = upperBound(zeroLeft, r) - 1;

            if (l_idx > m - 1 || r_idx < 0 || l_idx >= r_idx) {
                ans.push_back(cnt1);
                continue;
            }

            int leftLen =
                zeroRight[l_idx] - max(zeroLeft[l_idx], l) + 1;

            int rightLen =
                min(r, zeroRight[r_idx]) - zeroLeft[r_idx] + 1;

            if (l_idx + 1 == r_idx) {
                ans.push_back(cnt1 + leftLen + rightLen);
                continue;
            }

            int leftContri =
                leftLen + zeroBlocks[l_idx + 1];

            int rightContri =
                rightLen + zeroBlocks[r_idx - 1];

            int middleContri =
                st.query(l_idx + 1, r_idx - 2);

            ans.push_back(cnt1 + max({leftContri, rightContri, middleContri}));
        }

        return ans;
    }
};