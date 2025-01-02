class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int i = 0, j = 0;
        while(i < s.size()) {
            if(j < spaces.size() && i == spaces[j]) {
                ans.push_back(' ');
                j++;
            }
            else ans.push_back(s[i++]);
        }

        return ans;
    }
};