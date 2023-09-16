#include<iostream>
using namespace std;

void rec(int n)
{
    if(n == 0) return ;
    cout << n << endl;
    rec(--n);
    cout << n << endl;
}

int main(){
    rec(10);

    return 0;
}