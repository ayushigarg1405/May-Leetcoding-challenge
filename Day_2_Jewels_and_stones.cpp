/* You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.


Solution approach:

Used unordered_set for keep the characters of string J and then traversing S to find the characters present in J. 

Solution:

*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        int count = 0;
        for(int i=0;i<J.length();i++){
            s.insert(J[i]);
        }
        for(int i=0;i<S.length();i++){
            if(s.find(S[i])!=s.end())
                count++;
        }
        return count;
    }
};