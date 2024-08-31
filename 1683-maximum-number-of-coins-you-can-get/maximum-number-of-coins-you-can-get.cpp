class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<>());
        int maxx = piles.size()/3, sum = 0, i = 1;
        while(maxx--) {
            sum += piles[i];
            i+=2;
        }

        return sum;
    }
};