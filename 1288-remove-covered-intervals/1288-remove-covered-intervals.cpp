class Solution {
public:
    int solve(vector<vector<int>> &intervals){
        //sort by the start time and then if start times are equal sort in desc by the end time
        sort(begin(intervals),end(intervals),[&](auto &a,auto &b){
           if(a[0]==b[0])
               return a[1]>b[1];
            return a[0]<b[0];
        });
        int i=0,j=1,n=intervals.size(),count=0;
        if(n<=1)
            return n;
        int prev=0,cur=1;
        for(;prev<n and cur<n;){
            if(cur!=prev and intervals[cur][1]>=intervals[prev][0] and intervals[cur][1]<=intervals[prev][1]){
                count++;
                cur++;
            }
            else{
                prev=cur;
                cur++;
            }
        }
        //count - maxCoveredContigency
        cout<<count<<endl;
        return n-count;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        return solve(intervals);
        sort(begin(intervals),end(intervals),[&](auto &a,auto &b){
            if(a[0]==b[0])
                return a[1] > b[1];
            return a[0]< b[0];
        });
        int i=0,j=1,n=intervals.size(),count=0;
        if(n<=1)
            return n;
        int prev=0,cur=1;
        for(;prev<n && cur<n;){
            if(cur!=prev && intervals[cur][1]>=intervals[prev][0] && intervals[cur][1]<=intervals[prev][1]){
                count++;
                cur++;
            }
            else{
                prev=cur;
                cur++;
            }
        }
        return n-count;
    }
};