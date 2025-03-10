class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int arr[1001] = {0};

        for(int i = 0; i < 1001; i++) arr[i] = 0;

        for(int i = 0; i < nums1.size(); i++) {
            arr[nums1[i]]++;
        }
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++) {
            if(arr[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                arr[nums2[i]]--;
            }
        }

        return ans;
    }
};