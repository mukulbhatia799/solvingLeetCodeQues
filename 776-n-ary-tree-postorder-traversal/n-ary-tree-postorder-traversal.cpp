/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void findAns(Node* root, vector<int>& ans) {
        if(!root) return ;

        for(int i = 0; i < root->children.size(); i++) {
            findAns(root->children[i], ans);
            int value = root->children[i]->val;
            ans.push_back(value);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> answer;
        findAns(root, answer);
        if(root) answer.push_back(root->val);
        return answer;
    }
};