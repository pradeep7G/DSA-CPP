class Solution {
public:
    typedef pair<int,int> doublet;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<doublet,vector<doublet>,greater<doublet>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int i=0;
        for(auto x:mp){
            if(i>=k) 
            {
                if(pq.empty()==false && pq.top().first < x.second){
                    pq.pop();
                    pq.push({x.second,x.first});
                }
            }
            else
                pq.push({x.second,x.first});
            i++;
        }
        for(int i=0;i<k;i++){
            if(pq.empty()==false)
            {    ans.push_back(pq.top().second);
             pq.pop();
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};