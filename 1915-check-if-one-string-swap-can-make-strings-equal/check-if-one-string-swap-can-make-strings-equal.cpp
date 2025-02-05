class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        vector<int> harsh;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                harsh.push_back(i);
                count++;
            }
        }
        if(count==0 || (count==2 && ((s1[harsh[0]]==s2[harsh[1]]) && (s1[harsh[1]]==s2[harsh[0]])))){
            return true;
        }else{
            return false;
        }
    }
};