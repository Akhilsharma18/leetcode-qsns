class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> sum, sq, lazy;
     void update(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
     long long len = r - l + 1;
     sq[node] = (sq[node] + 2 * sum[node] + len) % MOD;
    sum[node] = (sum[node] + len) % MOD;
    lazy[node]++;
    return;
        }
      int mid = (l + r) / 2;
     if (lazy[node]) {
            for (int child : {node * 2, node * 2 + 1}) {
                int len = child == node * 2 ? mid - l + 1 : r - mid;
                long long val = lazy[node];
       sq[child] = (sq[child] + 2 * val * sum[child]
                            + len * val * val) % MOD;
         sum[child] = (sum[child] + len * val) % MOD;
                lazy[child] += val;
            }
            lazy[node] = 0;
        }
 if (ql <= mid)
            update(node * 2, l, mid, ql, qr);
 if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);
   sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }
 int sumCounts(vector<int>& nums) {
        int n = nums.size();
 sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
  unordered_map<int, int> last;
        long long ans = 0;
for (int i = 0; i < n; i++) {
            int prev = -1;
   if (last.count(nums[i]))
                prev = last[nums[i]];
  update(1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;
   ans = (ans + sq[1]) % MOD;
        }
 return ans;
    }
};