#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 3, m = 4;
    int arr[n][m] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> ans;
    int col = 0;
    while(col < m)
    {
        if(col & 1) {
            // odd -> bottom to top;
            for(int i = n-1; i >= 0; i--) {
                cout << "odd col: " << col << endl;
                ans.push_back(arr[i][col]);
            }
        }
        else {
            //even -> top to bottom;
            for(int i = 0; i < n; i++) {
                cout << "even col: " << col << endl;
                ans.push_back(arr[i][col]);
            }
        }
        col++;
    }

    cout << "Output: ";
    for(auto val: ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
Case 1:

Input:

1  2  3  4
5  6  7  8
9 10 11 12

Output: 1 5 9 10 6 2 3 7 11 12 8 4

*/