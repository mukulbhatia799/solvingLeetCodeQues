#include <bits/stdc++.h> 
using namespace std;

// using recursion
int findAns(int n, int d, vector<int>& arr, int s1, int s2) {
    if(n < 0) return (s1+arr[n]-s2) == d;

    int c1 = findAns(n-1, d, arr, s1+arr[n], s2);   // take
    int c2 = findAns(n-1, d, arr, s1, s2+arr[n]);   // not take

    return c1+c2;
}
int countPartitions(int n, int d, vector<int> &arr) {
    
    return findAns(n-1, d, arr, 0, 0);
}


// using memoization