#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& vec, int val) {
        int ptr2 = vec.size()-1, count = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            if(ptr2 < i) break;
            if(vec[i] == val)
            {
                while(ptr2 > i)
                {
                    if(vec[ptr2] == val) ptr2--;
                    else break;
                }
                swap(vec[ptr2], vec[i]);
            }
        }
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == val) break;
            count++;
        }
        return count;
    }

int main() {
    

    return 0;
}