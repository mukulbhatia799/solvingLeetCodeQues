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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int l1_val = (l1 != NULL)?l1->val:0;
            int l2_val = (l2 != NULL)?l2->val:0;
            int sum = l1_val + l2_val + carry;
            int val = sum%10;
            carry = (sum>9)?1:0;
            ListNode* newnode = new ListNode(val);
            if(head == NULL) {
                head = newnode;
                tail = newnode;
            }
            else {
                tail->next = newnode;
                tail = newnode;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) {
            ListNode* newnode = new ListNode(carry);
            tail->next = newnode;
            tail = newnode;
        }
        return head;
    }
};