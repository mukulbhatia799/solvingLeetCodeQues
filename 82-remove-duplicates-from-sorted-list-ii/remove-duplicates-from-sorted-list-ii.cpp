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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        while(curr && curr->next) {
            if(curr->val == curr->next->val) {
                int value = curr->val;
                while(curr && curr->val == value) curr = curr->next;
                if(prev == NULL) head = curr;
                else prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};