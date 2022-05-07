class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x=0,y=n;
        //brute solution create a new array and do simulation or can you solve it in O(n);
        
        for(int i=y;i<nums.size();i++)
        {
            nums[i]<<=10;
            nums[i]|=nums[i-n];
        }
        int i=0;
        for(int j=n;i<nums.size();j++)
        {
            int firstNum=nums[j]&1023;
            int secondNum=nums[j]>>10;
            nums[i]=firstNum;
            nums[i+1]=secondNum;
            i+=2;
        }
        return nums;
    }
};