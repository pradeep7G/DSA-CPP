class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // on search on rows and one on columns
        if(mat.size()==0 || mat[0].size()==0)
            return false;
        int rows=mat.size(),cols=mat[0].size();
        int low=0,high=rows-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cur=mat[mid][0];
            if(cur==target)
                return true;
            if(cur<target)
                low=mid+1;
            else
                high=mid-1;
        }
        int h=high;
        low=0,high=cols-1;
        if(h>=0)
        {
         while(low<=high){
            int mid=low+(high-low)/2;
            int cur=mat[h][mid];
            if(cur==target)
                return true;
            if(cur<target)
                low=mid+1;
            else
                high=mid-1;
        }   
        }
        return false;
    }
   
};