class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        int i = 0, j = 0, ans = 0, count = 0;

        while(j < n) {
            auto it = mp.find(s[j]);

            if(it != mp.end() && it->second >= i) {
                i = it->second+1;
                count = j-i+1;
            }
            else count++;
            mp[s[j]] = j;
            ans = max(ans, count);
            j++;
        }

        return ans;
    }
};