class Solution {
public:
    int solve(int index,int d){
        string nums;
        int num=d;
        for(;num;)
        {
            nums+=to_string(num%10);
            num/=10;
        }
        reverse(begin(nums),end(nums));
        char ch=nums[index];
        int ind=-1;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>=ch)
            {
             ch=nums[i];
             ind=i;
            }
        }
        if(ind==-1)
            return d;
        swap(nums[index],nums[ind]);
        return stoi(nums);
    }
    int maximumSwap(int d) {
        int digits=log10(d)+1;
        int ans=d;
        for(int i=0;i<digits;i++){
            ans=max(ans,solve(i,d));
        }
        return ans;
    }
};