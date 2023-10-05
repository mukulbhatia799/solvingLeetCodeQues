#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count100 = 0, count50 = 0, count20 = 0, count1 = 0;
    // while(n)
    // {
    //     if(n / 100 != 0)
    //     {
    //         count100 += n / 100;
    //         n -= 100*(n/100);
    //     }
    //     else if(n / 50 != 0)
    //     {
    //         count50 += n / 50;
    //         n -= 50*(n/50);
    //     }
    //     else if(n / 20 != 0)
    //     {
    //         count20 += n / 20;
    //         n -= 20*(n/20);
    //     }
    //     else {
    //         count1 += n;
    //         n = 0;
    //     }
    // }

    while(n)
    {
        int noofnotes = 0, token;
        if(n / 100 != 0) token = 100;
        else if(n / 50 != 0) token = 50;
        else if(n / 20 != 0) token = 20;
        else token = 1;
        switch (token)
        {
            case 100:
                noofnotes = n/100;
                n -= 100*noofnotes;
                cout << "There are " << noofnotes << " of 100." << endl;
                break;
            
            case 50:
                noofnotes = n/50;
                n -= 50*(n/50);
                cout << "There are " << noofnotes << " of 50." << endl;
                break;
            
            case 20:
                noofnotes = n/20;
                n -= 20*(n/20);
                cout << "There are " << noofnotes << " of 20." << endl;
                break;

            case 1:
                noofnotes = n;
                n = 0;
                cout << "There are " << noofnotes << " of 1." << endl;
                break;
            
            default:
                break;
        }
    }

    return 0;
}