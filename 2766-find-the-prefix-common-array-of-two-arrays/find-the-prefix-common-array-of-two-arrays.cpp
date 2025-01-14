class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;

        vector<int> ans;
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]] > 1) count++;
            if(A[i] != B[i] && mp[B[i]] > 1) count++;
            ans.push_back(count);
        }

        return ans;
    }
};