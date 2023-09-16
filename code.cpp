#include<iostream>
using namespace std;

void printNumbers(int n, string str[])
{
    if(n == 0) return;
    int mod = n % 10;
    cout << str[mod] << " ";
    printNumbers(n/10, str);
}

int main(){
    int n;
    cin >> n;

    string s[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    printNumbers(n, s);

    return 0;
}