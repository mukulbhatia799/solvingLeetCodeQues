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
    void Reverse(TreeNode* rootleft, TreeNode* rootright, int ind) {
        if(!rootleft) return;

        if(ind & 1) {
            swap(rootleft->val, rootright->val);
        }

        Reverse(rootleft->left, rootright->right, ind+1);
        Reverse(rootleft->right, rootright->left, ind+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        Reverse(root->left, root->right, 1);

        return root;
    }
};