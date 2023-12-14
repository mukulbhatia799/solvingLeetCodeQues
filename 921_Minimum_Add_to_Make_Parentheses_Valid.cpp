#include <iostream>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        // using stack data structure.
        string st;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push_back(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty())
                    count++;
                else
                    st.pop_back();
            }
        }
        count += st.size();

        return count;
    }
};

int main()
{

    return 0;
}