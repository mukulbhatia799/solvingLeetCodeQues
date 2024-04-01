#include <iostream>
#include <algorithm>
using namespace std;

string calc_Sum(int *a, int n, int *b, int m)
{
    string ans;
    int i = n - 1, j = m - 1, carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        int mod = sum % 10;
        ans += to_string(mod);
        i--;
        j--;
    }

    while (i >= 0)
    {
        ans += to_string(a[i] + carry);
        i--;
    }
    while (j >= 0)
    {
        ans += to_string(b[j] + carry);
        j--;
    }

    reverse(ans.begin(), ans.end());
    int store = stoi(ans);
    ans = to_string(store);
    return ans;
}

/*
5
0 3 5 4 3
4 
1 1 1 1
*/

int main()
{
    int n = 2, m = 6;
    int a[] = {9, 1}, b[] = {1 ,1 , 1, 1};

    string ans = calc_Sum(a, n, b, m);

    cout << ans << endl;


    return 0;
}