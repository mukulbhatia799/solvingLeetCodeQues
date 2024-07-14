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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = b-a+1;
        ListNode* temp = list1;
        ListNode* head = list1;
        while(a != 1)
        {
            temp = temp->next;
            a--;
        }
        ListNode* temp2 = temp;
        while(count--) {
            temp2 = temp2->next;
        }
        temp->next = list2;
        ListNode* temp3 = list2;
        while(temp3->next != NULL)
        {
            temp3 = temp3->next;
        }
        temp3->next = temp2->next;
        return head;
    }
};