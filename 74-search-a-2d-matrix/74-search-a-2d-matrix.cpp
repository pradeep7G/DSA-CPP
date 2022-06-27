class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // on search on rows and one on columns
         if(mat.size()==0 || mat[0].size()==0)
            return false;
        int rows=mat.size(),cols=mat[0].size();
       
        /*
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
        */
        
        //treating as continous sorted list
        int lo=0,hi=rows*cols-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int r=mid/cols,c=mid%cols;
            int cur=mat[r][c];
            if(cur==target)
                return true;
            if(cur<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return false;
    }
   
};