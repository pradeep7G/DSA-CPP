class Solution {
public:
    int MOD=1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int res=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
           int lo=i+1,hi=n-1;
           int c=target-arr[i];
           while(lo<hi){
               int sum=arr[lo]+arr[hi];
               if(sum==c){
                   int l=1,r=1;
                   if(arr[lo]==arr[hi]){
                       res=(res+(((hi-lo)*(hi-lo+1))/2)%MOD)%MOD;
                       break;
                   }
                   else{
                       //count same elements
                       while(lo+1<hi && arr[lo]==arr[lo+1])
                           lo++,l++;
                       while(lo<=hi-1 && arr[hi]==arr[hi-1])
                           hi--,r++;
                       lo++,hi--;
                       res=(res+(l*r))%MOD;
                   }
                   
               }
               else if(sum<c){
                   lo++;
               }
               else
                   hi--;
           }
        }
        return res;
    }
};