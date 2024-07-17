class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]-diff) != st.end() && st.find(nums[i]+diff) != st.end()) count++;
        }

        return count;
    }
};