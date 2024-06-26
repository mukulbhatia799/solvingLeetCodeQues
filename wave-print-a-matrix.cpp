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
    for(int col = 0; col < m; col++)
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
    }

    cout << "Output: column-wise: ";
    for(auto val: ans) {
        cout << val << " ";
    }
    cout << endl;



    // row-wise output
    for(int row = 0; row < n; row++) {
        if(row & 1) {
            // for odd row

        }
        else {
            // for even row
            
        }
    }

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