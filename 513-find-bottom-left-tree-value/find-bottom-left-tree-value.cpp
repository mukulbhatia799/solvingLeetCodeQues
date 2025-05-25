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
    int findBottomLeftValue(TreeNode* root) {
        pair<pair<int, int>, int> pr;  // <<row, col>, value>
        pr = {{INT_MIN, INT_MIN}, 0};
        findAns(root, pr, 0, 0);

        return pr.second;
    }
    void findAns(TreeNode* root, pair<pair<int, int>, int> &pr, int row, int col) {
        if(!root) return ;

        if(!root->left && !root->right) {
            if(row > pr.first.first) {
                pr = {{row, col}, root->val};
            }
        }

        findAns(root->left, pr, row+1, col-1);
        findAns(root->right, pr, row+1, col-1);
    }
};