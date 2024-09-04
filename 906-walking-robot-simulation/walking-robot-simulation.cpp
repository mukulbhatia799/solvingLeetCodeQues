class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(vector<int>& obs:obstacles)
        {
            string s=to_string(obs[0])+"_"+to_string(obs[1]);
            st.insert(s);
        }
        int x=0,y=0,maxdis=0;
        pair<int,int>dir={0,1};
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2){
                dir={-dir.second,dir.first};
            }
            else if(commands[i]==-1){
                dir={dir.second,-dir.first};
            }
            else{
                for(int step=0;step<commands[i];step++)
                {
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    string key=to_string(newx)+"_"+to_string(newy);
                    if(st.find(key)!=st.end())
                    {
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            maxdis=max(maxdis,(x*x)+(y*y));
        }
        return maxdis;
    }
};