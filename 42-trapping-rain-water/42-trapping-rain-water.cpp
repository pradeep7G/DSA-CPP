class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax[n],rightmax[n];
        leftmax[0]=height[0];
        int lmax=leftmax[0];
        for(int i=1;i<n;i++){
            lmax=max(lmax,height[i]);
            leftmax[i]=lmax;
        }
        rightmax[n-1]=height[n-1];
        int rmax=height[n-1];
        for(int i=n-2;i>=0;i--){
            rmax=max(rmax,height[i]);
            rightmax[i]=rmax;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ans;
    }
};