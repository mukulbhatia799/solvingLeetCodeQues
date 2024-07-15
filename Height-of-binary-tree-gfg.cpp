class Solution{
    public:
    void findHeight(Node* node, int count, int &maxCount) {
        if(!node) {
            maxCount = max(count, maxCount);
            return ;
        }
        
        findHeight(node->left, count+1, maxCount);
        findHeight(node->right, count+1, maxCount);
    }
    int height(struct Node* node){
        int maxCount = 0;
        findHeight(node, 0, maxCount);
        return maxCount;
    }
};