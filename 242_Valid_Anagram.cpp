/*approach: As, two strings are given s and t. We have to rearrange the t string characters in such a way that it should me string s. So,
Approach-1:
    Take an array arr of size 26 to store all characters count from (a-z) And store each character count in arr. Now run a loop for array arr where we will check whether the characters of string t are present is array of not. If present then do count-- of that index value else if not present then return false.
    Not again run a loop for array arr to check if any of the element left after comparing it with the string t. If we found any index value > 0 then return false. Else at last return true.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
#include <climits>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iomanip>

using namespace std;

bool isAnagram(string s, string t)
{
    int track[26];
    for (int i = 0; i < 26; i++)
        track[i] = 0;
    for (int i = 0; i < s.length(); i++)
        track[s[i] - 'a']++;
    for (int i = 0; i < t.length(); i++)
    {
        if (track[t[i] - 'a'] == 0)
            return false;
        else
            track[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (track[i] > 0)
            return false;
    }
    return true;
}

int main()
{

    return 0;
}