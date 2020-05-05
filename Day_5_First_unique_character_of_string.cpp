Question:

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Solution Approach:

Using unordered_map.

Solution:

class Solution {
public:
    int firstUniqChar(string s) {
        int idx = INT_MAX;
        unordered_map<char, int> map;
        
        for(int i = 0; i < s.size(); i++) {
            if(map.count(s[i]) == 0)
                map[s[i]] = i+1;
            else if(map[s[i]] > 0)
                map[s[i]] *= -1;
        }
        
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > 0)
                idx = min(idx, it->second);
        }
        return idx == INT_MAX ? -1 : idx-1;
    }
};

