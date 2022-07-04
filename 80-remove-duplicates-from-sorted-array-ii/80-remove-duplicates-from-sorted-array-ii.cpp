class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,cnt=1;
        while(i<n){
           while(i<n-1 && nums[i]==nums[i+1]){
               if(cnt>=2)
               {
                   i++;continue;
               }
               nums[j++]=nums[i++];
               cnt++;
           }
           nums[j++]=nums[i++];
           cnt=1;
        }
        return j;
    }
};