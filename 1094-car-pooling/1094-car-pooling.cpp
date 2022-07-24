class Solution {
public:
    bool optimal(vector<vector<int>>& trips, int capacity){
        int stops[1001]={0};
        for(auto &t:trips){
            stops[t[1]]+=t[0];
            stops[t[2]]-=t[0];
        }
        for(int i=0;i<=1000 && capacity>=0;i++){
            capacity-=stops[i];
        }
        return capacity>=0;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       //at from, we are adding passengers, at to we are removing passengers
       //Example:                                                                                                                       i1-------i2                                                                                                                 i3-------i4 ; at i1 we are adding x, passengers, at i3 we are adding y passengers, at i2 we are removing x passengers, at i4 we are removing y passengers, we just simulate this, at any point of time if we exceed the capacity we return false;
        // Time:O(NLOGN),Space:O(2*N);
        //Can we do better?? reduce time complexity!!
        //the time stamp constrants are very low, at any point of time, 0<=time<=1000, can we use this information to reduce timecomplexity; or can we reduce timecomplexity irrespective of time!! may be by using extra space!!
        return optimal(trips,capacity);
        vector<pair<int,int>> v;
        for(auto &t:trips)
        {
            v.push_back({t[1],t[0]});
            v.push_back({t[2],-t[0]});
        }
        sort(begin(v),end(v));
        int cap=0;
        for(auto i:v){
            cap+=i.second;
            if(cap>capacity)
                return false;
        }
        return true;
    }
};