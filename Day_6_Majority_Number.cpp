/* 
Question:

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

Solution Approach:
1. Create an unordered_map storing frequency of each value.
2. Find the largest freq and return the key.

Solution:
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                m[nums[i]]=1;
            }
            else
                m[nums[i]]++;
        }
        
        int maxx = INT_MIN;
        int j = 0;
        for(auto i : m){
            if(i.second > maxx){
                maxx = i.second;
                j = i.first;
            }
        }
        return j;
    }
};
