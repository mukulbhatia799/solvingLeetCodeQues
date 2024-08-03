class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> hash(1001, 0);

        for(int i = 0; i < target.size(); i++) {
            hash[target[i]]++;
        }

        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i]]--;
            if(hash[arr[i]] < 0) return false;
        }

        return true;
    }
};