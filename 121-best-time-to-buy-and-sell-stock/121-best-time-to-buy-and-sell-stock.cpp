class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallestsofar=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            smallestsofar=min(smallestsofar,prices[i]);
            ans=max(ans,prices[i]-smallestsofar);
        }
        return ans;
    }
};