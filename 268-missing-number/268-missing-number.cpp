class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int allxor=0;
        for(int i=1;i<=nums.size();i++)
            allxor^=i;
        int num_xor=accumulate(begin(nums),end(nums),0,[&](int x,int y){
            return x^y;
        });
        return num_xor ^ allxor;
    }
};