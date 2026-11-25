class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + k < n) ? rank[a + k] : -1;
                int y = (b + k < n) ? rank[b + k] : -1;

                return x < y;
            });
 temp[sa[0]] = 0;
 for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = rank[a];
                int b1 = rank[b];

                int a2 = (a + k < n) ? rank[a + k] : -1;
                int b2 = (b + k < n) ? rank[b + k] : -1;

                temp[b] = temp[a] +
                          (a1 != b1 || a2 != b2);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }
 vector<int> pos(n);
 for (int i = 0; i < n; i++)
            pos[sa[i]] = i;
 vector<int> lcp(n, 0);
        int h = 0;
 for (int i = 0; i < n; i++) {
  int r = pos[i];
  if (r == 0)
                continue;
 int j = sa[r - 1];
 while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }
  lcp[r] = h;
 if (h > 0)
                h--;
        }
 int ans = n + 1;
 for (int i = 0; i < n; i++) {
int r = pos[i];
  int mx = 0;
  if (r > 0)
                mx = max(mx, lcp[r]);
    if (r + 1 < n)
                mx = max(mx, lcp[r + 1]);
  if (mx < n - i)
                ans = min(ans, mx + 1);
        }
return ans == n + 1 ? -1 : ans;
    }
};