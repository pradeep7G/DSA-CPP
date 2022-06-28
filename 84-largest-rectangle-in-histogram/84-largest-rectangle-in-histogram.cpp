class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftsmaller(n,-1);
        vector<int> rightsmaller(n,n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()!=-1 && heights[s.top()]>heights[i]){
                rightsmaller[s.top()]=i;
                s.pop();
            }
            if(i>0 && heights[i]==heights[i-1]){
                leftsmaller[i]=leftsmaller[i-1];
            }
            else{
                leftsmaller[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rightsmaller[i]-leftsmaller[i]-1)*heights[i]);
        }
        return ans;
    }
};