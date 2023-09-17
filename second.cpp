#include<bits/stdc++.h>
using namespace std;

int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int countStu = 0, countWays = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            countStu++;
            if(i != nums.size()-1) {
                if(countStu < nums[i+1]) {
                    cout << "cs: " << countStu << endl;
                    countWays+=2;
                    break;
                }
                else if(countStu > nums[i]) countWays++;
            }
            else if(countStu > nums[i]) countWays++;
        }
        return countWays;
}

int main(){
    vector<int> vec{0,0,2,3,3,6,6};
    cout << countWays(vec);

    return 0;
}