class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[target[i]]++;
        }

        for(int i = 0; i < arr.size(); i++) {
            auto it = mp.find(arr[i]);
            if(it != mp.end()) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(it);
            }
            else return false;
        }

        if(mp.size() == 0) return true;
        return false;
    }
};