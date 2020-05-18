Question:

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.
Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Solution approach:

Maintaning the frequency array for string s1 and comparing with strings of length s1 in string s2.

Solution:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for(char c : s1) 
            freq1[c - 'a']++;
        int n = s1.size();
        vector<int> freq2(26, 0);
        for(int i = 0; i < s2.size(); i++)
        {
            freq2[s2[i] - 'a']++;
            if(i >= n) 
                freq2[s2[i-n] - 'a']--;            
            if(freq1 == freq2) 
                return true;
        }
        return false;
    }
};
