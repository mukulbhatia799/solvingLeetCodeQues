#include <iostream>
#include <vector>
using namespace std;

void reverseString(int x, string& s)
{
    int ptr1 = 0, ptr2 = x-1;
    string ans;
    while(ptr1 < ptr2)
    {
        swap(s[ptr1], s[ptr2]);
        ptr1++;
        ptr2--;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(i == x) continue;
        ans = ans + s[i];
    }
    cout << "ans: " << ans << endl;
    s = ans;
}
string finalString(string s) {
    int counti = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'i')
        {
            counti++;
            reverseString(i, s);
            i--;
        }
    }
    string ans;
    for(int i = 0; i < s.length(); i++)
    {
        ans = ans + s[i];
    }
    return ans;
}

int main() {
    string s = "string";
    cout << finalString(s);

	return 0;
}
