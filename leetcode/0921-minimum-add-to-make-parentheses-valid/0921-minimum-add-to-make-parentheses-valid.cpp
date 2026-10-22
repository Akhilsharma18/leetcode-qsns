class Solution {
public:
    int minAddToMakeValid(string s) {
        int openbracket = 0;
        int closebracket = 0;
 for (char ch : s) {
      if (ch == '(')
    openbracket++;
    else if (openbracket > 0)
   openbracket--;
            else
    closebracket++;
        }
 return openbracket + closebracket;
    }
};
