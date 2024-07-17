#include<bits/stdc++.h>
using namespace std;
long long int findAns(int n, int value, int *coins, map<pair<int, int>, long long int>& dp) {
    if(value == 0) return 1;
    if(n == 0) return (value%coins[n] == 0 ? 1:0);
    if(dp.find({n, value}) != dp.end()) return dp[{n, value}];
    // pick
    long long int pick = 0;
    if(coins[n] <= value) pick = findAns(n, value-coins[n], coins, dp);

    // not pick
    long long int notPick = findAns(n-1, value, coins, dp);

    return dp[{n, value}] = pick+notPick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // using memoization
    int sum = 0; for(int i = 0; i < n; i++) sum += denominations[i];
    map<pair<int, int>, long long int> dp;
    return findAns(n-1, value, denominations, dp);
}