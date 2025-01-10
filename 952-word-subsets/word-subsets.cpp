class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n = words1.size(), m = words2.size();
        int hash2[26] = {0};
        for(int i = 0; i < m; i++) {
            int dumyhash[26] = {0};
            for(char ch: words2[i]) {
                dumyhash[ch-'a']++;
            }
            for(int j = 0; j < 26; j++) {
                hash2[j] = max(hash2[j], dumyhash[j]);
            }
        }

        for(int i = 0; i < n; i++) {
            int hash1[26] = {0};

            for(char ch: words1[i]) {
                hash1[ch-'a']++;
            }

            bool check = true;
            for(int j = 0; j < 26; j++) {
                if(hash2[j] > 0 && hash1[j] < hash2[j]) {
                    check = false;
                    break;
                }
            }

            if(check) ans.push_back(words1[i]);
        }


        return ans;
    }
};