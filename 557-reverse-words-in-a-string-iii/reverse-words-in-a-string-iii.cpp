class Solution {
public:
    string reverseWords(string s) {
        string str = "", answer = "";
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(answer == "") answer = str;
                else answer = str + " " + answer;
                str = "";
            }
            else str.push_back(s[i]);
        }
        if(answer == "") answer = str;
        else answer = str + " " + answer;
        return answer;
    }
};