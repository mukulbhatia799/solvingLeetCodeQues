class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i = 0; i < s.length(); i++) {
            string x;
            x.push_back(s[i]);
            st.push(x);
            if(st.top() == "]") {
                st.pop();
                string Str;
                while(st.top() != "[") {
                    Str = st.top() + Str;
                    st.pop();
                }
                cout << "Str: " << Str << endl;
                st.pop();
                string strnum = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    strnum = st.top() + strnum;
                    st.pop();
                }
                int num = stoi(strnum);
                string temp = "";
                for(int j = 0; j < num; j++) {
                    temp = temp + Str;
                }
                if(!st.empty() && st.top().size() > 1) {
                    string topStr = st.top();
                    st.pop();
                    topStr += temp;
                    st.push(topStr);
                } else st.push(temp);
            }
        }
        if(st.size() > 1) {

            string str = "";
            while(st.size() > 1) {
                str = st.top() + str;
                st.pop();
            }
            string lastStr = st.top(); st.pop();
            lastStr = lastStr + str;
            st.push(lastStr);
        }
        return st.top();
    }
};