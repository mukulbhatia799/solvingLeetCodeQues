class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // hashmap approach
        int ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        for(int j = 0; j < t.size(); j++) {
            auto it = mp.find(t[j]);
            ans += abs(it->second-j);
        }

        return ans;
    }
};