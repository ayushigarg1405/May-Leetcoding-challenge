Question:

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation
Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 
Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

Solution approach:
1. Take the number given and find its bits using while loop till num!=1.
2. Keep pushing the bits to the stack.
3. Traverse the stack. Initialize variable count to stack size - 1 and result to 0.
4. if 1 is poped out, decreament the count and if 0 is poped out, add pow(2,count-1) to res.
5. return res.

Solution:

class Solution {
public:
    int findComplement(int num) {
        if(num==0)
            return 1;
            
        if(num==1)
            return 0;
            
        stack<int> s;
        while(num!=1){
            int n = num%2;
            num = num/2;
            s.push(n);
        }
        s.push(num);
        
        int res = 0;
        int count=s.size();
        
        while(s.empty()==false){
            int st = s.top();
            s.pop();
            if(st==1)
                count--;
            else{
                res = res + pow(2,count-1);
                count--;
            }
        }
        return res;
    }
};
