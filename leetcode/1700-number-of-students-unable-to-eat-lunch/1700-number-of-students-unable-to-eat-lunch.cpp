class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0 = 0, cnt1 = 0;
 for (int x : students) {
            if (x == 0)
                cnt0++;
            else
                cnt1++;
        }
    for (int s : sandwiches) {
            if (s == 0) {
                if (cnt0 == 0)
                    return cnt1;
           cnt0--;
            }
        else {
        if (cnt1 == 0)
         return cnt0;
                cnt1--;
            }
        }
 return 0;
    }
};