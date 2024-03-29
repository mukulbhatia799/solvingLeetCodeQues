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
    void storeLeaf(TreeNode* root, vector<int> &vec) {
        if(root && root->left == NULL && root->right == NULL) {
            vec.push_back(root->val);
            return ;
        }
        if(root == NULL) return ;
        
        storeLeaf(root->left, vec);
        storeLeaf(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        
        storeLeaf(root1, vec1);
        storeLeaf(root2, vec2);
        
        if(vec1.size() != vec2.size()) return false;
        else {
            for(int i = 0; i < vec1.size(); i++) {
                if(vec1[i] != vec2[i]) return false;
            }
            return true;
        }
    }
};