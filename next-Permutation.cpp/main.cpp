// #include <iostream>
// #include <algorithm>
// // #include<math.h>
// using namespace std;

// void findNextPerm(int *arr, int n, int i)
// {
//     if (i <= 0)
//     {
//         sort(arr, arr + n);
//         return;
//     }

//     if (arr[i] <= arr[i - 1])
//     {
//         findNextPerm(arr, n, i - 1);
//     }
//     else
//     {
//         sort(arr + i, arr + n);
//         swap(arr[i], arr[i - 1]);
//         return;
//     }
// } // may stuck when duplicates values are there.

// int main()
// {
//     // int arr[] = {2,3,1}; // output: 5, 5, 1, 5.
//     // int arr[] = {5, 1, 5, 5};      // output: 5, 5, 1, 5.
//     // int arr[] = {1,1,5,5};      // output: 1, 5, 1, 5.
//     int arr[] = {1, 2, 3};   // output: 1, 3, 2.
//     // int arr[] = {3,2,1};     // output: 1, 2, 3.
//     // int arr[] = {1, 2, 3, 6, 5, 4};  // output: 1, 2, 4, 3, 5, 6.
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "prev arr: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     findNextPerm(arr, n, n - 1);

//     cout << "next perm: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i, j;
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                break;
            }
        }

        if (i < 0)
        {
            sort(arr.begin(), arr.end());
            return;
        }
        // i = 1.

        for (j = i + 1; j < n; j++) // 2 3
        {
            if (arr[j] <= arr[i])
            {
                break;
            }
        }

        swap(arr[j - 1], arr[i]);

        sort(arr.begin() + i + 1, arr.end());
    }

int main()
{
    // vector<int> arr = {5, 0, 4, 0};
    vector<int> arr = {5, 7, 4, 0};
    int n = arr.size();

    cout << "perv Perm: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    nextPermutation(arr);

    cout << "next Perm: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}