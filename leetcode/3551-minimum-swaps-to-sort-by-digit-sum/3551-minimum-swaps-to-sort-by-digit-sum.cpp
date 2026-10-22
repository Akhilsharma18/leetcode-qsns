class Solution {
public:
    int digitSum(int x) {
   int sum = 0;
        while (x) {
 sum += x % 10;
  x /= 10;
        }
    return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
    vector<int> sorted = nums;
   sort(sorted.begin(), sorted.end(), [&](int a, int b) {
       int sa = digitSum(a);
     int sb = digitSum(b);
         if (sa == sb)
                return a < b;

            return sa < sb;
        });
       unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[sorted[i]] = i;
       vector<bool> vis(n, false);
        int swaps = 0;
      for (int i = 0; i < n; i++) {
         if (vis[i] || pos[nums[i]] == i)
                continue;
        int cycleSize = 0;
            int j = i;
       while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cycleSize++;
            }
     swaps += cycleSize - 1;
        }
    return swaps;
    }
};        
/*  ye ali approch jyada simple aew simple permutation + swapping knna 
int minSwaps(vector<int>& nums) {
        int n = nums.size();
 vector<pair<pair<int, int>, int>> arr;
for (int i = 0; i < n; i++) { 
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }
  sort(arr.begin(), arr.end());
 int swaps = 0;
for (int i = 0; i < n; i++) {
  if (arr[i].second == i)
   continue;
swaps++;
 swap(arr[i], arr[arr[i].second]);
        --i; 
      }
  return swaps;
    }
}*/