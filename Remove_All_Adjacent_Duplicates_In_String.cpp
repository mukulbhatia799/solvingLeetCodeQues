#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // using stack
        string st;
        for(int i = 0; i < s.length(); i++)
        {
            if(!st.empty() && s[i] == st[st.size()-1]) 
                st.pop_back();
            else 
                st.push_back(s[i]);
        }
        return st;
    }
};

int main()
{

    return 0;
}