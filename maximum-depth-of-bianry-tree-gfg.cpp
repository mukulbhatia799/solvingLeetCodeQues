class Solution{
  public:
    void findAns(Node* root, int count, int &maxCount) {
        if(!root) {
            maxCount = max(count, maxCount);
            return ;
        }
        
        findAns(root->left, count+1, maxCount);
        findAns(root->right, count+1, maxCount);
    }
    int maxDepth(Node *root) {
        int maxCount = 0;
        findAns(root, 0, maxCount);
        return maxCount;
    }
};