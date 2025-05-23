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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int res = findAns(root);
        cout << "res: " << res << endl;
        return max(res, ans);
    }

    int findAns(TreeNode* root) {
        if(root == NULL) return 0;

        int left = findAns(root->left);
        int right = findAns(root->right);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        ans = max(ans, left+right+root->val);
        return root->val + max(left, right);
    }
};