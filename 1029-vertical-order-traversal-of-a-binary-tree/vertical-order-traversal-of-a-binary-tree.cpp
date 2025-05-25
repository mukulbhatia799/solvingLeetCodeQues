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
    void getMapFilled(TreeNode* root, vector<pair<int, pair<int, int>>> &vpp, int row, int col) {
        if(!root) return ;

        vpp.push_back({col, {row, root->val}});

        getMapFilled(root->left, vpp, row+1, col-1);
        getMapFilled(root->right, vpp, row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<pair<int, pair<int, int>>> vpp;

        getMapFilled(root, vpp, 0, 0);

        sort(vpp.begin(), vpp.end());

        // cout << "after sorting" << endl;
        // for(auto pr: vpp) {
        //     cout << pr.first << " " << pr.second.first << " " << pr.second.second << endl;
        // }

        for(int i = 0; i < vpp.size(); i++) {
            int col = vpp[i].first;

            vector<int> curr;
            int check = false;
            while(i < vpp.size() && vpp[i].first == col) {
                int row = vpp[i].second.first;
                int val = vpp[i].second.second;
                curr.push_back(val);
                i++;
                check = true;
            }
            if(check) i--;
            ans.push_back(curr);
        }

        return ans;
    }
};