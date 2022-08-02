class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //kth smallest
        //Brute-force O(n^2logn^2) time and O(mn) space, store in an array and sort find kth smallest
        //Optimised: O(32nlogn) Binary search
        int lo=INT_MIN,hi=INT_MAX;
        while(lo<=hi){
            int mid=lo+((long long)hi-(long long)lo)/2;
            int count=0;
            for(int i=0;i<matrix.size();i++)
            {
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<=k-1){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return lo;
    }
};