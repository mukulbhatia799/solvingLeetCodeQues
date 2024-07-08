class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int prev = groups[0];
        vector<string> answer;
        answer.push_back(words[0]);
        for(int i = 1; i < groups.size(); i++) {
            if(groups[i] != prev) {
                answer.push_back(words[i]);
                prev = groups[i];
            }
        }
        return answer;
    }
};