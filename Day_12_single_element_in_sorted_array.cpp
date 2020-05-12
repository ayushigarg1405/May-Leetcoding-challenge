/*

Question:
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. 
Find this single element that appears only once.

Solution Approach:
Method 1 = traversing array for each element and check the next one. O(n) Time complexity
Method 2 = Binary search. Comparing the mid index. If it is even, value will be on left else it will be on right. O(logn) TC

Solution:
*/

Method 1 

int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[i+1])
                return nums[i];
            i++;
        }
        return -1;
    }
    
Method 2

int singleNonDuplicate(vector<int>& nums) {
	int start=0, end = nums.size()-1, mid;
	while( start < end ) {
		mid = start + (end-start)/2;
		if( nums[mid] == nums[mid ^ 1] )
			start = mid + 1;
		else
			end = mid;
	}
	return nums[start];
}
