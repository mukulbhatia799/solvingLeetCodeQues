class Solution {
public:
    string reverseWords(string s) {
        string str = "", answer = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                reverse(str.begin(), str.end());
                if(answer == "") answer = str;
                else answer = answer + " " + str;
                str = "";
            }
            else str.push_back(s[i]);
        }
        reverse(str.begin(), str.end());
        if(answer == "") answer = str;
        else answer = answer + " " + str;
        return answer;
    }
};