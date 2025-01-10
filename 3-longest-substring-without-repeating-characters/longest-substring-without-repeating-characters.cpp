class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        int i = 0, j = 0, ans = 0, count = 0;

        while(j < n) {
            auto it = mp.find(s[j]);
            if(it != mp.end()) {
                while(i < j && s[i] != s[j]) {
                    mp.erase(s[i++]);
                }
                i++;
                count = j-i+1;
            }
            else count++;
            ans = max(ans, count);
            mp[s[j]]++;
            j++;
        }

        return ans;
    }
};