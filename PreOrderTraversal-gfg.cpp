class Solution{
    public:
    void findAns(Node* root, vector<int>& ans) {
        if(root == NULL) return ;
        
        ans.push_back(root->data);
        findAns(root->left, ans);
        findAns(root->right, ans);
    }
    vector<int> preOrder(Node* root)
    {
        vector<int> ans;
        
        findAns(root, ans);
        return ans;
    }
};