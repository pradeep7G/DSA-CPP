class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prof(n+1,0);
        int minfar=prices[0];
        for(int i=1;i<n;i++)
        {
            prof[i]=max(prof[i-1],prices[i]-minfar);
            minfar=min(minfar,prices[i]);
        }
        int ans=prof[n-1],maxfar=prices[n-1];
        for(int i=n-1;i>0;i--)
        {
            ans=max(prof[i-1]+maxfar-prices[i],ans);
            maxfar=max(maxfar,prices[i]);
        }
        return ans;
    }
};