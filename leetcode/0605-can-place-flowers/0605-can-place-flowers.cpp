class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
            for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0) {
                int left = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == size - 1) ? 0 : flowerbed[i + 1];

                if(left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    count++;
                    i++;
                }
            }
        }
     return count >= n;
    }
};