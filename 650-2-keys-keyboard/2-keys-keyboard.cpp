class Solution {
public:
    int findAns(int n, int m,int x){
        if(m>=n) return 0;
        if(n%m==0) return 2+findAns(n,m+m,m);
        return 1+findAns(n,m+x,x);
    }
    int minSteps(int n) {     
        return findAns(n,1,1);
    }
};