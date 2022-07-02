class Solution {
public:
    int solve(vector<int> &cards){
        int res=INT_MAX,n=cards.size();
        int left=0,right=0;
        unordered_map<int,int> mp;
        for(;right<n;right++){
            mp[cards[right]]++;
            if(mp[cards[right]]==2){
                while(mp[cards[right]]==2){
                    res=min(res,right-left+1);
                    mp[cards[left++]]--;
                }
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
    int minimumCardPickup(vector<int>& cards) {
        return solve(cards);
        vector<int> cardVals(1000005,0);
        int windowStart=0,windowEnd=cards.size()-1;
        int ans=1000000;
        for(windowStart=0,windowEnd=0;windowEnd<cards.size();)
        {
            cardVals[cards[windowEnd]]++;
            if(cardVals[cards[windowEnd]]==2)
            {
                while(windowStart<windowEnd && cardVals[cards[windowEnd]]==2)
                {
                    ans=min(ans,windowEnd-windowStart+1);
                    cardVals[cards[windowStart]]--;
                    windowStart++;
                }
            }
            windowEnd++;
        }
        if(ans==1000000)return -1;
        return ans;
    }
};