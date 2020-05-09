/*
Question:
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Solution approach:

Checking square of number till it is less that actual input given.

Solution:
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i = 1;
        for(i=0;i*i<num;i++);
        return i*i==num;
    }
};
