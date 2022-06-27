class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // on search on rows and one on columns
        // if(mat.size()==0 || mat[0].size()==0)
        //     return false;
        // int rows=mat.size(),cols=mat[0].size();
        // int low=0,high=rows-1;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     int cur=mat[mid][0];
        //     if(cur==target)
        //         return true;
        //     if(cur<target)
        //         low=mid+1;
        //     else
        //         high=mid-1;
        // }
        // int h=high;
        // low=0,high=cols-1;
        // if(h>=0)
        // {
        //  while(low<=high){
        //     int mid=low+(high-low)/2;
        //     int cur=mat[h][mid];
        //     if(cur==target)
        //         return true;
        //     if(cur<target)
        //         low=mid+1;
        //     else
        //         high=mid-1;
        // }   
        // }
        // return false;
        
        //treating as continous sorted list
        
        // int low=0,high=rows*cols - 1;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     int cur=mat[mid/cols][mid%cols];
        //     if(cur==target)
        //         return true;
        //     else if(cur<target)
        //     {
        //         low=mid+1;
        //     }
        //     else
        //         high=mid-1;
        // }
        // return false;
        
        if(mat.size()==0 || mat[0].size()==0)
            return false;
        int rows=mat.size(),cols=mat[0].size();
        int lo=0,hi=rows-1,row=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int cur=mat[mid][0];
            if(cur==target)
                return true;
            if(cur<target){
                row=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        if(row!=-1){
            lo=0,hi=cols-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                int cur=mat[row][mid];
                if(cur==target)
                    return true;
                if(cur<target){
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
        }
        return false;
    }
   
};