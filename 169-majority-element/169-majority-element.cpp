class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=-1,cx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cx==0)
                x=nums[i],cx=1;
            else if(x==nums[i])
                cx++;
            else
                cx--;
        }
        cx=0;
        for(int i=0;i<n;i++)
            if(x==nums[i])
                cx++;
        if(cx > n/2)
            return x;
        return -1;
    }
};