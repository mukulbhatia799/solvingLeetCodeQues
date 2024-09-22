class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // brute force approach
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < t.size(); j++) {
                if(j != i && s[i] == t[j]) {
                    ans += abs(i-j);
                }
            }
        }

        return ans;
    }
};