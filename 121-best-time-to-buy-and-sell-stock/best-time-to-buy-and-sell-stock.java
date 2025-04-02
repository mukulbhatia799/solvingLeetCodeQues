class Solution {
    public int maxProfit(int[] prices) {
        int miniPrice = prices[0], maxProfit = 0;

        for(int i = 0; i < prices.length; i++) {
            if(prices[i] < miniPrice) miniPrice = prices[i];

            maxProfit = Math.max(maxProfit, prices[i]-miniPrice);
        }

        System.out.println("maxProfit: " + maxProfit);

        return maxProfit;
    }
}