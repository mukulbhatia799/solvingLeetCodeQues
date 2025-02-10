class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') st.push(s[i]);
            else {
                if(!st.empty()) st.pop();
            }
        }
        string ans = "";
        int size = st.size();
        for(int i = 0; i < size; i++) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};