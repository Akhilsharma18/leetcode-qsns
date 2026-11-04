
class Solution {
public:
    multiset<long long> left, right;
    long long sumLeft = 0, sumRight = 0;
 void add(long long num) {
        if (left.empty() || num <= *left.rbegin()) {
            left.insert(num);
            sumLeft += num;
        } else {
            right.insert(num);
            sumRight += num;
        }
balance();
    }
 void remove(long long num) {
        auto it = left.find(num);
  if (it != left.end()) {
            left.erase(it);
            sumLeft -= num;
        } else {
            it = right.find(num);
            right.erase(it);
            sumRight -= num;
        }

        balance();
    }

    void balance() {
        while (left.size() > right.size() + 1) {
            long long num = *left.rbegin();
            left.erase(left.find(num));
            sumLeft -= num;

            right.insert(num);
            sumRight += num;
        }

        while (left.size() < right.size()) {
            long long num = *right.begin();
            right.erase(right.find(num));
            sumRight -= num;

            left.insert(num);
            sumLeft += num;
        }
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);
   for (int i = 0; i < n; i++) {
            add(nums[i]);
 if (i >= x) {
                remove(nums[i - x]);
            }
if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }
 const long long INF = 1e18;
  vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);
 for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);
  for (int i = 1; i <= n; i++) {
            curr[i] = curr[i - 1];
if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
