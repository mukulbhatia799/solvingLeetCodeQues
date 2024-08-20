/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findAns(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = findAns(nums, low, mid-1);
        root->right = findAns(nums, mid+1, high);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return findAns(nums, 0, nums.size()-1);
    }
};