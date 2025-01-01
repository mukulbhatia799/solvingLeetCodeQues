class Solution {
public:
    int maxScore(string s) {
        int c0 = 0, c1 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') c1++;
        }
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '0') c0++;
            else c1--;
            ans = max(ans, c0+c1);
        }
        return ans;
    }
};