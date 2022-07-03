class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
      vector<int> res(nums.size(),-1);
      int n=nums.size(),left=0,right=0;
      long long sum=0;
      for(;right<n;right++){
          sum+=nums[right];
          if(right<2*k)
              continue;
          res[(right+left)/2]=(sum/(right-left+1));
          sum-=nums[left++];
      }
      return res;
    }
};