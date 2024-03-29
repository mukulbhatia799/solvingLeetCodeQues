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
    int deepestLeavesSum(TreeNode* root) {
        // find the sum of the leaf nodes.
        /*
        approach: using level order traversal, we can store the sum of each level and check if next level is present in that tree or not. If not, that is the answer.
        */

        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);

        int sum = 0;
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
    // #if 0
    //     else {
    //         TreeNode* temp = q.front();
    //         q.pop();
    //         q.pop();
    //         if(temp->left) {
    //             q.push(temp->left); sum += temp->left->val;
    //         }
    //         if(temp->right) {
    //             q.push(temp->right); sum += temp->right->val;
    //         }
    //         // q.push
    //     }
    // #endif
        int lastsum = -1;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                if(!q.empty()) {
                    lastsum = sum;
                    sum = 0;
                    q.push(NULL);
                }
                else return lastsum;
            }
            else {
                if(temp->left) {
                    sum += temp->left->val;
                    q.push(temp->left);
                }
                if(temp->right) {
                    sum += temp->right->val;
                    q.push(temp->right);
                }
            }
        }

        return -1;
    }
};