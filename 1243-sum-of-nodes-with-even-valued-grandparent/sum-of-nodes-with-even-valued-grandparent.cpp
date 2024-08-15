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
    void findAns(TreeNode* root, int prev, int gp, int depth, int &sum) {
        if(!root) return ;

        if(depth == 0)  gp = root->val;
        else if(depth == 1) prev = root->val;
        else if(gp%2 == 0) {
            sum += root->val;
        }

        if(depth >= 2) {
            gp = prev;
            prev = root->val;
        }

        findAns(root->left, prev, gp, depth+1, sum);
        findAns(root->right, prev, gp, depth+1, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int arr[2];
        int sum = 0;
        findAns(root, 0, 0, 0, sum);
        return sum;
    }
};