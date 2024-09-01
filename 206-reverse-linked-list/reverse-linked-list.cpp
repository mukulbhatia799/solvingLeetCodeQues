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
    void findAns(ListNode* &head, ListNode* prev, ListNode* curr) {
        if(curr == NULL) {
            head = prev;

            return ;
        }
        cout << curr->val << " ";
        findAns(head, curr, curr->next);
        curr->next = prev;
        if(prev) prev->next = NULL;
    }
    ListNode* reverseList(ListNode* head) {
        findAns(head, NULL, head);

        return head;
    }
};