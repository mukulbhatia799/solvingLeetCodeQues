class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;  // <subdomain, count-paired>
        for(int i = 0; i < cpdomains.size(); i++) {
            string currStr = cpdomains[i], strNum = "", str = "";
            int num = 0, j = 0;
            while(currStr[j] != ' ') {
                strNum += currStr[j++];
            }
            num = stoi(strNum);
            int k = currStr.size()-1;
            while(k >= j) {
                if(currStr[k] == '.' || currStr[k] == ' ') {
                    cout << "str: " << str << endl;
                    mp[str] += num;
                }
                str = currStr[k--] + str;
            }
        }
        vector<string> ans;
        for(auto it: mp) {
            string str = to_string(it.second) + " " + it.first;
            ans.push_back(str);
        }
        return ans;
    }
};