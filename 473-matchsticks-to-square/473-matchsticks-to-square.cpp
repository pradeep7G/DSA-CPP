class Solution {
public:
    typedef long long ll;
    bool dfs(vector<int> &nums,int index,vector<ll> &sides,ll side){
        if(index>=nums.size()){
            if(sides[0]==side and sides[1]==side and sides[2]==side and sides[3]==side)
                return true;
            return false;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+nums[index]>side or (i>0 and sides[i]==sides[i-1]) or sides[i]==side)
                continue;
            sides[i]+=nums[index];
            if(dfs(nums,index+1,sides,side))
                return true;
            sides[i]-=nums[index]; //backtrack
        }
        return false;
    }
    // bool dfs(vector<int> &nums,int index,vector<long long> &sides,long long side){
    //     if(index>=nums.size())
    //     {
    //         if(sides[0]==side && sides[1]==side && sides[2]==side && sides[3]==side)
    //             return true;
    //         return false;
    //     }
    //     for(int i=0;i<4;i++){
    //         if(sides[i]+nums[index]>side || (i>0 && sides[i]==sides[i-1]))
    //             continue;
    //         sides[i]+=nums[index];
    //         if(dfs(nums,index+1,sides,side))
    //             return true;
    //         sides[i]-=nums[index];
    //     }
    //     return false;
    // }
    bool makesquare(vector<int>& matchsticks) {
        // int n=
        if(matchsticks.size()<4)
            return false;
        long long sum=accumulate(matchsticks.begin(),matchsticks.end(),0LL);
        if(sum%4!=0)
            return false;
        long long side=sum/4;
        sort(matchsticks.begin(),matchsticks.end());
        long long sideSum=0;
        //dfs , backtracking
        vector<long long> sides(4,0);
        return dfs(matchsticks,0,sides,side);
        return true;
    }
};