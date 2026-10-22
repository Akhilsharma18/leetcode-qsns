class Solution {
public:
    int largestInteger(int num) {

    string temp = to_string(num);
      vector<int> odd;
    vector<int> even;
        int n = num;
      while (n != 0) {
            int rem = n % 10;
            if (rem % 2 == 0)
                even.push_back(rem);
        else
              odd.push_back(rem);
            n /= 10;
        }
        sort(even.rbegin(), even.rend());
   sort(odd.rbegin(), odd.rend());
        int res = 0;
        int k = 0, i = 0, j = 0;
        while (k < temp.size()) {
            if ((temp[k] - '0') % 2 == 0) {
                res = res * 10 + even[i];
                i++;
            } else {
                res = res * 10 + odd[j];
                j++;
            }
            k++;
        }
        return res;
    }
};