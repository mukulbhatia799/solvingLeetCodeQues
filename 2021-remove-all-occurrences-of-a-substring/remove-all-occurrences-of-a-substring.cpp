class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part); // return -1 if not found

        while(pos != -1) {
            s.erase(pos, part.size());
            pos = s.find(part);
        }

        return s;
    }
};