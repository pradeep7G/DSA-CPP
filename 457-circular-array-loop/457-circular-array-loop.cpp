class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        //i have O(N^2) and O(1) / O(N) and O(N) solutions. but O(N) and O(1)'' for that i guess we need to use nums for visited boolean check, since nums are in [-1000,1000];
        int n=nums.size();
        bool isforward=false;
        for(int i=0;i<n;i++){
            // if(nums[i]>1000)
            //     continue;
            isforward=nums[i]>=0;
            int slow=i,fast=i;
            do{ 
                slow=findnextindex(slow,isforward,nums);
                fast=findnextindex(fast,isforward,nums);
                if(fast!=-1){
                    fast=findnextindex(fast,isforward,nums);
                }
                // if(slow!=-1){
                //     nums[slow]+=5000;
                // }
            }while(slow!=-1 && fast!=-1 && slow!=fast);
            if(slow!=-1 && slow==fast)
            {
                return true;
            }
        }
        return false;
    }
    int findnextindex(int i,bool isforward,vector<int> &nums){
        bool direction=nums[i]>=0;
        if(isforward!=direction)
            return -1;
        int index=(i+nums[i]+nums.size())%nums.size();
        if(index==i)
            return -1;
        return index;
    }
};