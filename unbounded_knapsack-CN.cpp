#include<bits/stdc++.h>
using namespace std;


/*



int findAns(int n, int w, vector<int>& profit, vector<int>& weight) {
    if(n < 0) {
        return 0;
    }

    int take = 0;
    if(w >= weight[n]) take = profit[n] + findAns(n, w-weight[n], profit, weight);
    int notTake = findAns(n-1, w, profit, weight);

    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // using recursion
    return findAns(n-1, w, profit, weight);
}

*/


/*



int findAns(int n, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp) {
    if(n < 0) {
        return 0;
    }

    if(dp[n][w] != -1) return dp[n][w];

    int take = 0;
    if(w >= weight[n]) take = profit[n] + findAns(n, w-weight[n], profit, weight, dp);
    int notTake = findAns(n-1, w, profit, weight, dp);

    return dp[n][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // using memoization
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    return findAns(n-1, w, profit, weight, dp);
}

*/