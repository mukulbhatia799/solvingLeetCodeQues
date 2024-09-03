class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        string s = "";
        while(x) {
            char mod = (x % 10) + '0';
            s.push_back(mod);
            x /= 10;
        }
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};