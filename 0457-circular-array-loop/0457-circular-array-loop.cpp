class Solution {
public:
    bool solve(vector<int> &nums){
        unordered_map<int,int> mp;
        int n=size(nums);
        bool isforward=false;
        for(int i=0;i<n;i++){
            if(mp.count(i))
                continue;
            isforward=nums[i]>=0;
            int slow=i,fast=i;
            do {
                slow=findNextIndex(slow,isforward,nums);
                mp[slow]++;
                fast=findNextIndex(fast,isforward,nums);
                if(fast!=-1){
                    fast=findNextIndex(fast,isforward,nums);
                }
            } while(slow!=-1 and fast!=-1 and slow!=fast);
            if(slow!=-1 and slow==fast)
                return true;
        }
        return false;
    }
    int findNextIndex(int idx,bool isforward,vector<int> &nums){
        bool dir=nums[idx]>=0;
        if(dir!=isforward)
            return -1;
        int index=(idx+nums[idx]+size(nums))%size(nums);
        if(index==idx)
            return -1;
        return index;
    }
    bool circularArrayLoop(vector<int>& nums) {
        //i have O(N^2) and O(1) / O(N) and O(N) solutions. but O(N) and O(1)'' for that i guess we need to use nums for visited boolean check, since nums are in [-1000,1000];
        return solve(nums);
        int n=nums.size();
        bool isforward=false;
        for(int i=0;i<n;i++){
            isforward=nums[i]>=0;
            int slow=i,fast=i;
            do{ 
                slow=findnextindex(slow,isforward,nums);
                fast=findnextindex(fast,isforward,nums);
                if(fast!=-1){
                    fast=findnextindex(fast,isforward,nums);
                }
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