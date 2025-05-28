/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findAns(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        TreeNode* leftSub = findAns(root->left, p, q);
        TreeNode* rightSub = findAns(root->right, p, q);

        if(leftSub && rightSub) {
            return root;
        }
        else if(root->val == p->val || root->val == q->val) {
            return root;
        }
        else if(leftSub || rightSub) {
            return (leftSub ? leftSub:rightSub);
        }
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Method 2: After checking the left and right substree of a node, check if leftsubtree or rightsubtree return the non-null value or not. If both left and right subtree returns then the current node is the answer node, else if one of the side returns means the either the second node is not found or both the nodes were on same path and the node above the lower node is the answer node.
        return findAns(root, p, q);
    }
};