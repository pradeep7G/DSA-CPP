class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0;
        int n=nums.size();
        int left=0,right=0;
        int sum=0,cnt=0;
        if(goal==0){
           for(int i=0,j=1;i<n;i++){
               if(nums[i]==0)
               {   
                   cnt+=j,j++;
               }
               else
                   j=1;
           }
            return cnt;
        }
        for(;right<n;right++){
            if(nums[right]==1){
                sum++;
                // if(sum>goal)
                //     sum--;
                if(sum>=goal){
                    cnt=1;
                    while(!(nums[left++]==1)){
                        cnt++;
                    }
                    res+=cnt;
                }
            }
            else if(sum>=goal){
                res+=cnt;
            }
        }
        return res;
    }
};