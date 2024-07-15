class Solution{
    public:
    void findAns(Node* node, vector<int>& ans) {
        if(!node) return ;
        
        findAns(node->left, ans);
        findAns(node->right, ans);
        ans.push_back(node->data);
    }
    vector<int> postOrder(Node* node) {
        vector<int> ans;
        findAns(node, ans);
        return ans;
    }
};