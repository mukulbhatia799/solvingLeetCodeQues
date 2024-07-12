class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> vec;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            if(cnt < 0) {
                cnt = 0;
                continue; 
            }
            vec.push_back(s[i]);
        }
        string ans;
        for(int i = vec.size()-1; i >= 0; i--) {
            if(vec[i] == '(' && cnt) {
                cnt--;
                continue;
            }
            ans.push_back(vec[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};