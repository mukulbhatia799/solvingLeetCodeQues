class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), count = 0;
        for(int i = 0; i < n; i++) {
            int j = 0;
            while(j < words[i].size() && words[i][j] == pref[j]) j++;
            if(j == pref.size()) count++;
        }

        return  count;
    }
};