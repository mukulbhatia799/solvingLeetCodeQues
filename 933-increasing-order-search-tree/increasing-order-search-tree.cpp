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
    void findAns(TreeNode* root, vector<int>& store) {
        if(!root) return ;

        findAns(root->left, store);
        store.push_back(root->val);
        findAns(root->right, store);
    }
    TreeNode* createNewTree(int i, vector<int>& store) {
        if(i == store.size()) return NULL;
        TreeNode* newnode = new TreeNode(store[i]);
        newnode->left = NULL;
        newnode->right = createNewTree(i+1, store);
        return newnode;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> store;
        findAns(root, store);
        return createNewTree(0, store);
    }
};