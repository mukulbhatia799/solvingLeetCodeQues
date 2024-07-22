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
    TreeNode* findAns(vector<int>&nums, int left, int right) {
        if(left > right) return NULL;

        int mid = INT_MIN, maxx = INT_MIN;
        for(int i = left; i <= right; i++) {
            if(maxx < nums[i]) {
                maxx = nums[i];
                mid = i;
            }
        }

        TreeNode* newnode = new TreeNode(nums[mid]);
        newnode->left = findAns(nums, left, mid-1);
        newnode->right = findAns(nums, mid+1, right);

        return newnode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return findAns(nums, 0, nums.size()-1);
    }
};