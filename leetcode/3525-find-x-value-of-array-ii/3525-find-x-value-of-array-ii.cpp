class SegmentTree {
private:
    static const int MAXK = 6;
 int k;
    int n;
    vector<array<int, MAXK>> tree;
 void makeLeaf(int node, int value) {
        tree[node].fill(0);
  int remainder = value % k;
        tree[node][remainder] = 1;
        tree[node][k] = remainder;
    }
 array<int, MAXK> merge(
        const array<int, MAXK>& left,
        const array<int, MAXK>& right
    ) {
        array<int, MAXK> result{};
        result.fill(0);
 int mulLeft = left[k];
        int mulRight = right[k];
 for (int x = 0; x < k; ++x) {
            result[x] = left[x];
        }
  for (int x = 0; x < k; ++x) {
            int remainder = (mulLeft * x) % k;
            result[remainder] += right[x];
        }
 result[k] = (mulLeft * mulRight) % k;
return result;
    }
 void maintain(int node) {
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
 void build(const vector<int>& nums, int node, int left, int right) {
        if (left == right) {
            makeLeaf(node, nums[left]);
            return;
        }
  int mid = left + (right - left) / 2;
  build(nums, node * 2, left, mid);
        build(nums, node * 2 + 1, mid + 1, right);
 maintain(node);
    }

public:
    SegmentTree(const vector<int>& nums, int k) {
        this->k = k;
        this->n = nums.size();
        tree.resize(4 * n + 5);
 build(nums, 1, 0, n - 1);
    }
 void update(int node, int left, int right, int index, int value) {
        if (left == right) {
            makeLeaf(node, value);
            return;
        }
 int mid = left + (right - left) / 2;
 if (index <= mid) {
            update(node * 2, left, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, right, index, value);
        }
  maintain(node);
    }  array<int, MAXK> query(
        int node,
        int left,
        int right,
        int queryLeft,
        int queryRight
    ) {
        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        }
  int mid = left + (right - left) / 2;
       if (queryRight <= mid) {
            return query(
                node * 2,
                left,
                mid,
                queryLeft,
                queryRight
            );
        }
 if (queryLeft > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                right,
                queryLeft,
                queryRight
            );
        }
  auto leftResult = query(
            node * 2,
            left,
            mid,
            queryLeft,
            queryRight
        );
      auto rightResult = query(
            node * 2 + 1,
            mid + 1,
            right,
            queryLeft,
            queryRight
        );
 return merge(leftResult, rightResult);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
       SegmentTree seg(nums, k);
        vector<int> answer(queries.size());
         for (int i = 0; i < (int)queries.size(); ++i) {
            int index = queries[i][0];
            int value = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];
           seg.update(1, 0, n - 1, index, value);
            auto result = seg.query(1, 0, n - 1, start, n - 1);
            answer[i] = result[x];
        }

        return answer;
    }
};