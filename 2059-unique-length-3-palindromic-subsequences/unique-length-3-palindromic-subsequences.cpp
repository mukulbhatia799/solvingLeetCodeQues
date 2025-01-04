class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> start(26, -1), end(26, -1);
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i]-'a';
            if(start[ch] == -1) start[ch] = i;
            end[ch] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(start[i] != -1 && end[i] != -1) {
                unordered_set<char> st;
                for(int j = start[i]+1; j < end[i]; j++) {
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }

        return ans;
    }
};