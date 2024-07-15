class Solution {
public:
    void findAns(Node* node, vector<int>& ans) {
        if(!node) return ;
        
        findAns(node->left, ans);
        ans.push_back(node->data);
        findAns(node->right, ans);
    }
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        findAns(root, ans);
        return ans;
    }
};