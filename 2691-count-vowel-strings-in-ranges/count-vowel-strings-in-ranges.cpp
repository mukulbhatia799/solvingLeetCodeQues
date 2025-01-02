class Solution {
public:
    bool checkVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> hash(words.size(), 0);
        int pfSum = 0;
        for(int i = 0; i < words.size(); i++) {
            if(checkVowel(words[i][0]) && checkVowel(words[i][words[i].size()-1])) hash[i]++;
            pfSum += hash[i];
            hash[i] = pfSum;
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            int count = 0;
            if(start == 0) count = hash[end];
            else count = hash[end] - hash[start-1];
            
            ans.push_back(count);
        }

        return ans;
    }
};