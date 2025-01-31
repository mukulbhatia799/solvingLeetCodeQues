class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> e(n);
        vector<vector<bool>> c(n,vector<bool>(n,0));
        vector<int> s;
        vector<bool> r;
        for(auto pr : p)
            e[pr[0]].push_back(pr[1]);
        for(auto i = 0U; i < n; i++) {
            vector<bool> v(n,0);
            v[i] = 1;
            s.push_back(i);
            while(s.size()) {
                auto j = s.back();
                s.pop_back();
                for(auto k : e[j])
                    if(!v[k]) {
                        v[k] = 1;
                        c[i][k] = 1;
                        s.push_back(k);
                    }
            }
        }
        for(auto qr : q)
            r.push_back(c[qr[0]][qr[1]]);
        return r;
    }
};