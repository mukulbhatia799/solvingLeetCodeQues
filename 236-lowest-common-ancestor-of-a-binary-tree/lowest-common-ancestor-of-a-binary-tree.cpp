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
    void findAns(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &ppath, vector<TreeNode*> &qpath, bool& pfound, bool& qfound) {
        if(!root) return ;

        if(!pfound) ppath.push_back(root);
        if(!qfound) qpath.push_back(root);
        if(!pfound && root->val == p->val) {
            pfound = true;
        }
        else if(!qfound && root->val == q->val) {
            qfound = true;
        }

        findAns(root->left, p, q, ppath, qpath, pfound, qfound);
        findAns(root->right, p, q, ppath, qpath, pfound, qfound);
        if(!pfound) ppath.pop_back();
        if(!qfound) qpath.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Method 1: find path of both p and q nodes and store in diff vector. start comparing them from the starting. If at some point both comparisons mismatch, the last matched node will be the LCA of p and q.
        vector<TreeNode*> ppath;
        vector<TreeNode*> qpath;

        bool pfound = false, qfound = false;
        findAns(root, p, q, ppath, qpath, pfound, qfound);
        cout << "p path: ";
        for(auto node: ppath) {
            cout << node->val << "->";
        }
        cout << endl;
        cout << "q path: ";
        for(auto node: qpath) {
            cout << node->val << "->";
        }
        cout << endl;
        int i = 0, j = 0;
        TreeNode* lastCommonNode = NULL;
        while(i < ppath.size() && j < qpath.size()) {
            if(ppath[i] == qpath[j]) {
                lastCommonNode = ppath[i];
            }
            else break;
            i++; j++;
        }
        return lastCommonNode;
    }
};