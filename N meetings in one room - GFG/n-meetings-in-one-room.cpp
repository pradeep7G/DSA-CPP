// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        // vector<pair<int,int>> mergedvals;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        //Sorting by start time  and handling edge cases like 1 - 6 and 3 - 4.
        // sort(v.begin(),v.end());
        // mergedvals.push_back(v[0]);
        // for(int i=1;i<n;i++){
        //     pair<int,int> cur=v[i];
        //     if(cur.first==mergedvals.back().first){
        //         if(cur.second<mergedvals.back().second){
        //             mergedvals.back().second=cur.second;
        //         }
        //     }
        //     else if(cur.first > mergedvals.back().second){
        //         mergedvals.push_back(cur);
        //     }
        //     else if(cur.first>mergedvals.back().first && cur.second <mergedvals.back().second){
        //         mergedvals.pop_back();
        //         mergedvals.push_back(cur);
        //     }
        // }
        // return mergedvals.size();
        
        //sort by end time and find count;
        
        //Sorting by end time and no need to take care of 1 - 6 and 3 - 4 coz 3 - 4 will be the one than the latter as to have maximum meetings  we choose meetings that ends early
        // sort(v.begin(),v.end(),[&](auto a,auto b){
        //   if(a.second==b.second)   
        //     return a.first > b.first;
        //   if(a.second < b.second)
        //     return true;
        //     else
        //         return false;
        // });
        
        // int cnt=1;
        // auto prev=v[0];
        // for(int i=1;i<n;i++){
        //     if(v[i].first > prev.second)
        //     {
        //         cnt++;
        //         prev=v[i];
        //         continue;
        //     }
        // }
        // return cnt;
        
        //Practice
        sort(v.begin(),v.end(),[&](auto a,auto b){
           if(a.second==b.second) {
               a.first < b.first;
           }
           return a.second < b.second;
        });
        int count=1;
        auto prev=v[0];
        for(int i=1;i<n;i++){
            auto cur=v[i];
            if(cur.first > prev.second){
                count++;
                prev=cur;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends