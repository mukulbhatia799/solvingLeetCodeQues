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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *lessthan_ptr = NULL, *grEq_ptr = NULL, *lesshead = NULL, *grhead = NULL;

        ListNode* temp = head;

        while(temp) {
            ListNode* newnode = new ListNode(temp->val);
            if(temp->val < x) {
                if(lessthan_ptr == NULL) {
                    lessthan_ptr = lesshead = newnode;
                }
                else {
                    lessthan_ptr->next = newnode;
                    lessthan_ptr = newnode;
                }
            }
            else {
                if(grEq_ptr == NULL) {
                    grEq_ptr = grhead = newnode;
                }
                else {
                    grEq_ptr->next = newnode;
                    grEq_ptr = newnode;
                }
            }

            temp = temp->next;
        }

        if(lessthan_ptr == NULL) head = grhead;
        else if(grEq_ptr == NULL) head = lesshead;
        else {
            lessthan_ptr->next = grhead;
            head = lesshead;
        } 

        return head;
    }
};