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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vec;
        ListNode* temp = head;

        while(temp) {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int l = left-1, r = right-1;
        while(l < r) swap(vec[l++], vec[r--]);

        ListNode* curr = NULL;
        int i = 0;
        while(i < vec.size()) {
            ListNode* newnode = new ListNode(vec[i++]);
            if(!curr) curr = head = newnode;
            else {
                curr->next = newnode;
                curr = newnode;
            }
        }

        return head;
    }
};