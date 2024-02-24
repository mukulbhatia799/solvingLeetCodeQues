/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void recursiveRemoval(ListNode* &head, ListNode* prev, ListNode* curr, int &currmax)
    {
        if(curr == NULL) return ;
        recursiveRemoval(head, curr, curr->next, currmax);
        if(curr->val < currmax) {
            if(curr == head) {
                head = head->next;
                delete curr;
            }
            else {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
            }
        }
        else currmax = curr->val;
    }
    ListNode* removeNodes(ListNode* head) {
        int currmax = INT_MIN;
        ListNode *curr = head;
        ListNode *prev = NULL;
        recursiveRemoval(head, prev, curr, currmax);
        return head;
    }
};