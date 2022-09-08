class Solution {
public:
    typedef long long ll;
    int binarySearch(int end,vector<vector<int>> &rides){
        int lo=0,hi=rides.size()-1;
        int ans=rides.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(rides[mid][0]>=end){
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    } 
    ll solve(vector<ll> &dp,vector<vector<int>> &rides,int index){
        if(index>=rides.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        vector<int> tmp={rides[index][1],INT_MIN,INT_MIN};//next best index, if we try lower_bound,be sure values at index 1,2 be INT_MIN,INT_MIN
        int nextIndex=lower_bound(begin(rides),end(rides),tmp)-begin(rides);
        if(nextIndex==index)
            nextIndex++;
        // int nextIndex=binarySearch(rides[index][1],rides);//at same time driver can drop-off and pick up new passenger, so upper_bound doesn't work
        //don't pick
        ll val1=solve(dp,rides,index+1);
        //pick
        ll val2=rides[index][2]+solve(dp,rides,nextIndex);
        return dp[index]=max(val1,val2);
    }
    long long maxTaxiEarnings(int x, vector<vector<int>>& rides) {
        //dp with binary search same as finding two best non-overlapping intervals
        int n=rides.size();
        vector<ll> dp(n,-1);
        sort(rides.begin(),rides.end());
        for(int i=0;i<n;i++)
            rides[i][2]+=rides[i][1]-rides[i][0];
        return solve(dp,rides,0);
    }
};