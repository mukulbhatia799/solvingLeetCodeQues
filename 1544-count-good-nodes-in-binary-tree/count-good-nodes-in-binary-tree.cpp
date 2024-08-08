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
    void findAns(TreeNode* root, int greatest, int &count) {
        if(!root) return ;
        if(root->val >= greatest) {
            count++;
            greatest = root->val;
        }
        findAns(root->left, greatest, count);
        findAns(root->right, greatest, count);
    }
    int goodNodes(TreeNode* root) {
        int greatest = root->val, count = 0;
        findAns(root, greatest, count);
        return count;
    }
};