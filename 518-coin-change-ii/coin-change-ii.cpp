class Solution {
public:
    int findAns(vector<int>& coins, int amount, int i, map<pair<int, int>, int> &mp) {
        if(i >= coins.size() || amount == 0) return (amount == 0);
        if(mp.find({i, amount}) != mp.end()) return mp[{i, amount}];
        int pick = 0;
        if(amount-coins[i] >= 0) pick = findAns(coins, amount-coins[i], i, mp);
        int notPick = findAns(coins, amount, i+1, mp);
        return mp[{i,amount}] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int sum = 0;
        for(int val: coins) sum += val;
        map<pair<int, int>, int> mp;
        return findAns(coins, amount, 0, mp);
    }
};