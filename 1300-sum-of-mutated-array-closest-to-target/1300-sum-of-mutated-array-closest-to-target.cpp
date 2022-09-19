class Solution {
public:
    vector<int> pre;
    // int check(int val,vector<int> &arr,int target){
    //     int index=upper_bound(arr.begin(),arr.end(),val)-arr.begin()-1;
    //     int valSum=0;
    //     if(index>-1){
    //         valSum+=pre[index];
    //     }
    //     valSum+=((arr.size()-index-1)*val);
    //     return abs(valSum-target);
    // }
    int check(int val,vector<int> &arr,int target){
        int idx=upper_bound(begin(arr),end(arr),val)-begin(arr)-1;
        int valSum=0;
        if(idx>=0)
            valSum+=pre[idx];
        valSum+=((arr.size()-idx-1)*val);
        return abs(valSum-target);
    }
    int solve(vector<int> &arr,int target){
        sort(begin(arr),end(arr));
        int n=arr.size();
        pre.resize(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+arr[i];
        int lo=0,hi=1e5+5;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,arr,target)>check(mid+1,arr,target)){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
    int findBestValue(vector<int>& arr, int target) {
        //binary search? Yes. Expected TC: O(NlogN)
        return solve(arr,target);
        sort(arr.begin(),arr.end());
        //solution space will be x+y-1,x+y-2 .... x ... x+y+1 .. X+y+2.. so we need global minima
        int n=arr.size();
        pre.resize(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+arr[i];
        int lo=0,hi=1e5 + 2;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,arr,target)>check(mid+1,arr,target)){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return lo;//lo==hi
    }
};