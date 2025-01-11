class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return 0;

        unordered_map<char, int> cnt;

        for (char ch : s) cnt[ch]++;

        int ans = 0;
        for (auto& it : cnt) {
            if (it.second % 2 != 0) ans++;
        }

        return ans <= k;
    }
};