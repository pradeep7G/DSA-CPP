class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefSums(n+1,0),sufSums(n+1,0);
        for(int i=1;i<n;i++)
        {
            prefSums[i]=prefSums[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            sufSums[i]=sufSums[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            cout<<prefSums[i]<<" "<<sufSums[i]<<"\n";
            if(prefSums[i]==sufSums[i])
                return i;
        }
        return -1;
    }
};