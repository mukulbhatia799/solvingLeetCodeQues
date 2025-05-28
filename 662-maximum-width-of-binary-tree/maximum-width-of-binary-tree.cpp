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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        else if(!root->left && !root->right) return 1;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        q.push({NULL, -1});

        int miniIndexAtLevel = 0, ans = 1, first = -1, second = -1;
        while(!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();

            if(curr.first == NULL) {
                if(!q.empty()) {
                    ans = max(ans, q.back().second-q.front().second+1);
                    miniIndexAtLevel = q.front().second;
                    q.push({NULL, -1});
                }
            }
            else {
                // cout << "nodeValue: " << curr.first->val << " index: " << curr.second << endl;
                if(curr.first->left) q.push({curr.first->left, (long long)2*(curr.second-miniIndexAtLevel)+1});
                if(curr.first->right) q.push({curr.first->right, (long long)2*(curr.second-miniIndexAtLevel)+2});
            }
        }

        return ans;
    }
};