class Solution {
public:
    int MOD=1e9 + 7;
    int solvehashmap(vector<int> &A,int target){
        unordered_map<int, long> c;
        for (int a : A) c[a]++;
        long res = 0;
        //i<j<k if sum==target order doesn't matter we assume i<k<j as i<j<k - basic
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
    int threeSumMulti(vector<int>& arr, int target) {
        return solvehashmap(arr,target);
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