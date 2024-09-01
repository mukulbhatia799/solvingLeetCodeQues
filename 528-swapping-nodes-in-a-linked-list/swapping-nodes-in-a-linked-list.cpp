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
    void findAns(ListNode* head, int &k, ListNode* &first, ListNode* &last, int ind) {
        if(!head) return ;

        if(ind == k) first = head;
        findAns(head->next, k, first, last, ind+1);

        k--;
        last = head;
        if(k == 0) {
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = NULL;
        ListNode* last = NULL;

        findAns(head, k, first, last, 1);

        return head;
    }
};