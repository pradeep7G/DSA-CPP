class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(begin(nums),end(nums));
        reverse(begin(nums),begin(nums)+k);
        reverse(begin(nums)+k,end(nums));
    }
};