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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) 
            return NULL;

        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;
        int sum = val1 + val2;
        TreeNode* newnode = new TreeNode(sum);
        TreeNode*left1 = root1 ? root1->left : NULL;
        TreeNode* left2 = root2 ? root2->left : NULL;
        newnode->left = mergeTrees(left1, left2);
        TreeNode* right1 = root1 ? root1->right : NULL;
        TreeNode* right2 = root2 ? root2->right : NULL;
        newnode->right = mergeTrees(right1, right2);

        return newnode;
    }
};