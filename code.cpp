// 5 per product

// 10 


#include<iostream>
using namespace std;

class salesperson
{
    int commbefore200 = 5;
    int commafter200 = 10;
public:
    void commissionofsp(int nop, int* am)
    {
        if(nop <= 200) *am = nop*commbefore200;
        else {
            int x = nop-200;
            *am = 200*commbefore200;
            *am += x*commafter200;
        }
    }
};

int main(){
    salesperson sp;
    int noofproduct;
    cout << "Enter how much product you want to buy: ";
    cin >> noofproduct;
    int amount = 0;
    sp.commissionofsp(noofproduct, &amount);
    cout << "Your amount for " << noofproduct << " products is " << amount << ".";

    return 0;
}