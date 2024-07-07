class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles, extra = 0;
        while(numBottles)
        {
            numBottles += extra;
            int n = numBottles;
            numBottles /= numExchange;
            extra = n % numExchange;
            sum += numBottles;
        }
        return sum;
    }
};