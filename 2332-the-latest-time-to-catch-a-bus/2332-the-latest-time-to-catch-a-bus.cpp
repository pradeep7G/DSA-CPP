class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pas, int cap) {
        sort(bus.begin(),bus.end());
        sort(pas.begin(),pas.end());
        priority_queue<int,vector<int>,greater<int>> pq(begin(pas),end(pas));
        map<int,vector<int>> mp;
        unordered_set<int> pas_arr;
        for(auto i:pas)
            pas_arr.insert(i);
        for(auto i:bus)
            mp[i]={};
        for(auto i:bus){
            int dep=i;
            int k=0;
            while(!pq.empty() && k<cap){
                if(pq.top()<=dep){
                    int top=pq.top();
                    pq.pop();
                    mp[dep].push_back(top);
                    k++;
                }
                else{
                    
                    break;
                }
            }
        }
        int ans=-1;
        for(auto i:mp){
            if(i.second.empty() || i.second.size()<cap){
                if(pas_arr.find(i.first)==pas_arr.end()){
                    ans=max(ans,i.first);
                }
            }
            for(auto arrival:i.second){
                if(pas_arr.find(arrival-1)==pas_arr.end()){
                    ans=max(ans,arrival-1);
                }
            }
        }
        return ans;
    }
};