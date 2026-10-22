class Solution {
public:
   bool palindrome(int i ,int j , string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int cnt= 0;
      for(int i = 0 ; i < n ; i++){
            for(int j = i; j <n ; j++){
                if(palindrome(i , j , s) && j-i+1 >=k){
                    cnt++;
                    i=j;
                    break;
                }
                if(j-i+1>k) break;
            }
        }

        return cnt;
    }
};