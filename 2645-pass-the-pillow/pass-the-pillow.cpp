class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 2;
        bool direction = 0;
        if(i == n) direction = !direction;
        time--;
        while(time != 0) {
            if(!direction) i++;
            else i--;
            if(i == n || i == 1) direction = !direction;
            time--;
        }
        return i;
    }

};