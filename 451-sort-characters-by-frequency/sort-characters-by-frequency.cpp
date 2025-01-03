bool comp(pair<char, int> &p1, pair<char, int> &p2) {
    return p1.second > p2.second;
}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        vector<pair<char, int>> vp(mp.begin(), mp.end());

        sort(vp.begin(), vp.end(), comp);

        string ans;
        for(auto it: vp) {
            char ch = it.first;
            int count = it.second;
            while(count--) {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};