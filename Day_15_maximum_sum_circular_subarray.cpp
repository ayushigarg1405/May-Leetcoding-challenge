Question:

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Solution Approach:

Maintaning the min and max sum.

Solution:

Naive Sloution:
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size()==1)
            return A[0];
        long long int sum = INT_MIN;
        long long int n = A.size();
        for(int i=0;i<n;i++){
            long long int subsum = A[i];
            sum = max(sum,subsum);
            for(int j=i+1;j%n!=i;j++){
                subsum += A[j%n];
                sum = max(sum,subsum);
            }
        }
        return sum;
    }
};

Efficient Solution:

int maxx=INT_MIN,minn=INT_MAX,sum1=0,sum2=0,tsum=0;   
        for(auto x:A)
        {
            tsum+=x; sum1+=x; sum2+=x;
            maxx=max(maxx,sum1);
            if(sum1<0) sum1=0;
            minn=min(sum2,minn);
            if(sum2>0) sum2=0;
        }
        if(tsum==minn) return maxx;             // if all the elements of array are negative.
        else return max(maxx,tsum-minn);
      
