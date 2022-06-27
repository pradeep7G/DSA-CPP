class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
              swap(nums[i][j],nums[j][n-i-1]);
              swap(nums[i][j],nums[n-i-1][n-j-1]);
              swap(nums[i][j],nums[n-j-1][i]);
            }
        }
    }
};