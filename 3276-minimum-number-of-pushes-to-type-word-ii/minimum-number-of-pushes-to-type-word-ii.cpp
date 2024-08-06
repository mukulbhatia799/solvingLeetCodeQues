class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for(int i = 0; i < word.size(); i++) {
            mp[word[i]]++;
        }

        vector<int> vec;
        for(auto it: mp) {
            vec.push_back(it.second);
        }

        sort(vec.begin(), vec.end(), greater<int>());

        cout << "displaying: ";
        for(auto it: vec) cout << it << " ";

        int x = 1, ans = 0;
        for(int i = 0; i < vec.size(); i++) {
            if(i == 8*x) x++;
            ans += vec[i]*x;
        }

        return ans;
    }
};