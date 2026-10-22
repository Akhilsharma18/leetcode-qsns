/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>ans;
       for(int i=1;i<=1000;i++)
        {
            int left=1,right=1000;
          while(left<=right)
            {
                int mid=(left+right)/2;
                if(customfunction.f(i,mid)==z)
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(mid);
                    ans.push_back(temp);
                    break;
                }
                else if(customfunction.f(i,mid)>z)
                    right=mid-1;
                else
                    left=mid+1;
            }
            if(customfunction.f(i,1)>z)
                break;
        }
        return ans;
    }
};