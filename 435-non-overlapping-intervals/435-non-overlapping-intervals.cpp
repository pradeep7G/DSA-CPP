class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto &a,auto &b){
            return a[1]<b[1];
        });
        int res=0;
        int n=intervals.size();
        int i=1;
        auto prev=0;
        for(;i<n;){
            auto cur=i;
            if(intervals[cur][0]<intervals[prev][1]){
                res++;
            }
            else{
                prev=cur;
            }
            i++;
        }
        return res;
    }
};