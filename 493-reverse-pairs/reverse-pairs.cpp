class Solution {
public:
    void func(vector<int>&nums, int low, int mid, int high) {
        int leftSize = mid-low+1;
        int rightSize = high-mid;

        vector<int> leftArr(leftSize, 0), rightArr(rightSize, 0);
        // int leftArr[leftSize];
        // int rightArr[rightSize];

        for(int i = 0; i < leftSize; i++) {
            leftArr[i] = nums[low+i];
        }
        for(int i = 0; i < rightSize; i++) {
            rightArr[i] = nums[mid+1+i];
        }

        int i = 0, j = 0, temp = low;
        while(i < leftSize && j < rightSize) {
            if(leftArr[i] <= rightArr[j]) nums[temp++] = leftArr[i++];
            else nums[temp++] = rightArr[j++];
        }

        while(i < leftSize) nums[temp++] = leftArr[i++];
        while(j < rightSize) nums[temp++] = rightArr[j++];
    }
    int countPairs(vector<int>& nums , int low, int mid, int high) {
        int count = 0;
        int j = mid+1;
        for(int i = low; i <= mid; i++) {
            while(j <= high && nums[i] > (long long)nums[j]*2) j++;
            count += j-(mid+1);
        }
        return count;
    }
    int findAns(vector<int>& nums, int low, int high) {
        int count = 0;
        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        count += findAns(nums, low, mid);
        count += findAns(nums, mid+1, high);
        count += countPairs(nums, low, mid, high);
        func(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return findAns(nums, 0, nums.size()-1);
    }
};