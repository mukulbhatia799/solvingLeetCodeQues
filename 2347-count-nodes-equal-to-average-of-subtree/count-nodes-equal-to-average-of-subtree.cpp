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
    pair<int, int> findAns(TreeNode* root, int &ans) {
        if(!root) return {0, 0};

        pair<int, int> leftpr = findAns(root->left, ans);
        pair<int, int> rightpr = findAns(root->right, ans);
        int n = leftpr.second + rightpr.second + 1;
        int sum = leftpr.first + rightpr.first + root->val;
        if(sum/n == root->val) ans++;
        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        findAns(root, ans);
        return ans;
    }
};