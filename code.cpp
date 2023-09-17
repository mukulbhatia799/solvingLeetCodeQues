#include<bits/stdc++.h>
using namespace std;

int minimumRightShifts(vector<int>& nums) {
        int check = -1;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1]) {
                check = i;
                break;
            }
        }
        if(check == -1) return 0;
        for(int i = check+1; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1]) return -1;
        }
        if(nums[0] < nums[nums.size()-1]) return -1;
        cout << "check: " << check << endl;
        return nums.size()-check-1;
    }

int main(){

    return 0;
}