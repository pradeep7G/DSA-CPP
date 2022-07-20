class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        //global inversions include local inversions so it's only possible when local inversions are global inversions
        //trivial case would be couting no.of global inversion and counting local inversions
        //compare and return but here all numbers are in range [0,n-1] and unique so it means we should me somehow able to use that advantage
        //explore possibilities
        //4; 1,0,3,2 the no.of local inversions should be the global inversions - statement
        //4: 0,1,3,2
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-i)>1)
                return false;
        }
        return true;
    }
};