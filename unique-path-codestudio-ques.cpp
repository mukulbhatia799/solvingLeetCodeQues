// using recursion
#include <bits/stdc++.h> 

int findAns(int m, int n) {
    if(m == 0 && n == 0) return 1;

    int sum = 0;
    if(m-1 >= 0) sum += findAns(m-1, n);
    if(n-1 >= 0) sum += findAns(m, n-1);

    return sum;
}


int uniquePaths(int m, int n) {
	return findAns(m-1, n-1);
}
