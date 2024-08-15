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
    void findValues(TreeNode* root, vector<int>& vec) {
        if(!root) return ;

        findValues(root->left, vec);
        vec.push_back(root->val);
        findValues(root->right, vec);
    }

    TreeNode* findAns(vector<int>& vec, int low, int high) {
        if(low > high) return NULL;

        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = findAns(vec, low, mid-1);
        root->right = findAns(vec, mid+1, high);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        findValues(root, vec);

        return findAns(vec, 0, vec.size()-1);
    }
};