class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(char ch: s) {
            st.push(ch);
            if(st.top() == '*') {
                st.pop();
                if(!st.empty()) {
                    st.pop();
                }
            }
        }
        s.clear();
        int size = st.size();
        for(int i = 0; i < size; i++) {
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());

        return s;
    }
};