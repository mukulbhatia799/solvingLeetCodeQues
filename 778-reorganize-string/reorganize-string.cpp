
class Info {
public:
    char ch;
    int chCount;

    Info(char ch, int  chCount) {
        this->ch = ch;
        this->chCount = chCount;
    }
};

class compare {
public:
    bool operator() (Info ch1, Info ch2) {
        return (ch1.chCount < ch2.chCount);
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // approach: Here we will create max heap of pair<char, charCount> and put each character of top() and top()-1 element one by one and update the heap.
        priority_queue<Info, vector<Info>, compare> pq;
        int hash[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            int index = s[i]-'a';
            hash[index]++;
        }

        // store the character with it's count in pq.
        for(int i = 0; i < 26; i++) {
            if(hash[i] > 0) {
                Info temp(i+'a', hash[i]);
                pq.push(temp);
            }
        }

        // now pick two largest characters and decrement them by one assuming that you are putting them in a vector. Then, again push them in pq.
        string ans = "";
        while(pq.size() > 1) {
            Info large1 = pq.top();
            pq.pop();
            Info large2 = pq.top();
            pq.pop();

            ans.push_back(large1.ch);
            ans.push_back(large2.ch);

            large1.chCount--;
            large2.chCount--;

            if(large1.chCount > 0) pq.push(large1);
            if(large2.chCount > 0) pq.push(large2);
        }

        if(pq.size() == 1) {
            Info large1 = pq.top();
            pq.pop();
            ans.push_back(large1.ch);
            large1.chCount--;
            if(large1.chCount > 0) return "";
        }

        return ans;
    }
};