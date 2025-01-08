class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(words[i].size() <= words[j].size()) {
                    int k = 0;
                    while(k < words[i].size()) {
                        if(words[i][k] != words[j][k]) break;
                        k++;
                    }
                    if(k == words[i].size()) {
                        k = words[j].size() - words[i].size();
                        int l = 0;
                        while(k < words[j].size()) {
                            if(words[i][l] != words[j][k]) break;
                            k++; l++;
                        }
                        if(k == words[j].size()) count++;
                    }
                }
            }
        }

        return count;
    }
};