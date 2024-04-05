#include <iostream>
using namespace std;

string makeGood(string s)
{
    // stack<char> st;

    string st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.size() > 0 && (st[st.size() - 1] - 32 == s[i] || st[st.size() - 1] == s[i] - 32))
        {
            st.pop_back();
        }
        else
        {
            st.push_back(s[i]);
        }
    }
    return st;
}

int main()
{
    string s = "leEeetcode"; // leetcode

    string answer = makeGood(s);

    cout << "answer: " << answer << endl;

    return 0;
}