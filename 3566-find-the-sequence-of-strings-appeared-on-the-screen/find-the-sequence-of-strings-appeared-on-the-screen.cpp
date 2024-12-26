class Solution {
public:
    vector<string> stringSequence(string target) {
        string str = "";
        vector<string> ans;
        for(int i = 0; i < target.size(); i++) {
            str.push_back('a');
            ans.push_back(str);
            while(str[i] != target[i]) {
                str[i]++;
                ans.push_back(str);
            }
        }

        return ans;
    }
};