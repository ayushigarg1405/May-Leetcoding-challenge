Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

Solution Approach:
1. Create an unordered map with char values as keys and freq of characters as value.
2. Iterate over magazine and increase the count of each char.
3. Next, take ransomNote string.
4. For every char in string - if char is present in map then decrease the freq of that  char by 1 
                              and if the char is not present, then return false
5. Return true if string is valid.

Solution:

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for (char c: magazine) 
            freq[c]++;
        for (char c: ransomNote){
            if (freq[c]) 
                freq[c]--;
            else 
                return false;
        }
        return true;
    }
};
