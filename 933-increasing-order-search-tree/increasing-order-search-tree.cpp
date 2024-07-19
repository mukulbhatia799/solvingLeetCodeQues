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
    void findAns(TreeNode* root, TreeNode* &root2) {
        if(!root) return ;

        findAns(root->left, root2);
        TreeNode* newnode = new TreeNode(root->val);
        root2->right = newnode;
        root2 = newnode;
        findAns(root->right, root2);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* root2 = new TreeNode();
        TreeNode* temp = root2;
        findAns(root, root2);
        return temp->right;
    }
};