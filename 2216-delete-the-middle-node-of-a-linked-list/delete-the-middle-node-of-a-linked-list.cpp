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
    int countNodes(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return NULL;
        }
        ListNode* temp = head;
        
        int count = countNodes(head) / 2;
        
        ListNode* prev = NULL;
        
        while(count--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        
        return head;
    }
};