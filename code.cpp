#include<iostream>
using namespace std;

void printFibUptoN(int n, int a, int b)
{
    if(n == 0) return;
    int c = a + b;
    cout << c << " ";
    printFibUptoN(--n, b, c);
}

int main(){
    cout << 0 << " " << 1 << " ";
    printFibUptoN(10, 0, 1);

    return 0;
}