class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> arr;
        for(int i = 0; i < 1001; i++) arr[i] = 0;

        for(int i = 0; i < nums1.size(); i++) {
            arr[nums1[i]] = 1;
        }

        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++) {
            if(arr[nums2[i]] == 1) {
                ans.push_back(nums2[i]);
                arr[nums2[i]] = -1;
            }
        }
        return ans;
    }
};