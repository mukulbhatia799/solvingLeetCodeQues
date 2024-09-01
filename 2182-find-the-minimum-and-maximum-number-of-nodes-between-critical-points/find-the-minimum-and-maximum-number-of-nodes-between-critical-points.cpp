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
    void findAns(ListNode* prev, ListNode* head, int& prevInd, int &mini, int &maxi, int& index, int& startInd) {
        if(!head->next) return ;

        if((head->val > prev->val && head->next->val < head->val) || (head->val < prev->val && head->next->val > head->val)) {
            if(prevInd == -1) prevInd = startInd = index;
            else {
                cout << "startInd: " << startInd << endl;
                mini = min(mini, index-prevInd);
                maxi = index-startInd;
                prevInd = index;
            }
        }

        index++;
        findAns(head, head->next, prevInd, mini, maxi, index, startInd);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1, -1};

        int prev = -1, mini = 1e6, maxi = 0, firstInd = -1, index = 1;
        findAns(head, head->next, prev, mini, maxi, index, firstInd);

        if(mini == 1e6) return {-1, -1};

        return {mini, maxi};
    }
};