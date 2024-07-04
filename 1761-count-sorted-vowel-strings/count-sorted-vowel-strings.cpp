class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);  // when n = 1, each vowel occurs 1 time. So, 5 ans. 
        // when n = 2, starting with o, there can be cases oo, ou as the string should be lexic. sorted.
        for(int i = 1; i < n; i++) {
            for(int j = 3; j >= 0; j--) {
                dp[j] += dp[j+1];
            }
        }

        int sum = 0;
        for(int ele: dp) sum += ele;
        return sum;

    }
};