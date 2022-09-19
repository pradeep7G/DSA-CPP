class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //group elements into 3 and remove them, check if the final elements remaining are valid or not;
        int n=nums.size();
        int x=INT_MIN,y=INT_MIN,cx=0,cy=0;
        for(int i=0;i<n;i++){
            if(x==nums[i])cx++;
            else if(y==nums[i])cy++;
            else if(cx==0)x=nums[i],cx=1;
            else if(cy==0)y=nums[i],cy=1;
            else cx--,cy--;
        }
        cx=0,cy=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x)cx++;
            if(nums[i]==y)cy++;
        }
        vector<int> res;
        if(cx > n/3)res.push_back(x);
        if(cy > n/3)res.push_back(y);
        return res;
    }
};