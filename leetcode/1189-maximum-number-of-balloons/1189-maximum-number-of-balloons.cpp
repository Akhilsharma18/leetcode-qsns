class Solution {
public:
    int maxNumberOfBalloons(string text) {
int akhil[5] = {0};
string chars = "balon";
for (char ch : text)
for (int i = 0; i < 5; i++)
akhil[i] += (ch == chars[i]);
return min({akhil[0], akhil[1], akhil[2] / 2, akhil[3] / 2, akhil[4]});
    }
};