class Solution {
public:
    bool findPq(priority_queue<int, vector<int>, greater<int>> pq, int val) {
        while(!pq.empty()) {
            if(pq.top() == val) return false;
            pq.pop();
        }
        return true;
    }

    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int maxi = INT_MIN, i = 0;

        while(pq.size() != 3 && i < nums.size()) {
            maxi = max(maxi, nums[i]);
            if(findPq(pq, nums[i])) pq.push(nums[i]);
            i++;
        }

        while(i < nums.size()) {
            maxi = max(maxi, nums[i]);
            if(nums[i] > pq.top() && findPq(pq, nums[i])) {
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }

        if(pq.size() < 3) return maxi;

        return pq.top();

        
    }
};