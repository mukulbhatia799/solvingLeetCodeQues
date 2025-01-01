class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++) {
            while(s[i] == ' ') i++;
            string str = "";
            while(i < s.size() && s[i] != ' ') str.push_back(s[i++]);
            if(i == s.size() && str.size()) {
                if(ans.size() != 0) ans = str + ' ' + ans;
                else ans = str;
            }
            else if(str.size()) {
                if(ans.size() != 0) ans = str + ' ' + ans;
                else ans = str;
            }
        }

        return ans;
    }
};