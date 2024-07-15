class Solution {
  public:
    int getSize(Node* node) {
        if(!node) return 0;
        
        int left = 0, right = 0;
        if(node->left) left =  getSize(node->left);
        if(node->right) right = getSize(node->right);
        
        return 1 + left + right;
    }
};