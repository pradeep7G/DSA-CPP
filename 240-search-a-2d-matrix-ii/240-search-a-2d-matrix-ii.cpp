class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //  divide and conquer,follow up: what is that time complexity??
        int m=matrix.size(),n=matrix[0].size();
        return approach2(matrix,target);
    }
    bool approach2(vector<vector<int>> &mat,int target){
        int m=mat.size(),n=mat[0].size();
        int j=n-1,i=0;
        for(;j>=0 and i<m;){
            if(mat[i][j]==target)
                return true;
            else if(mat[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
    bool solve(vector<vector<int>> &mat,int left,int top,int right,int bottom,int target){
        if(right<left || bottom<top)
            return false;
        int pivotX=left+(right-left)/2;
        int pivotY=top+(bottom-top)/2;
        int cur=mat[pivotX][pivotY];
        if(cur==target)
            return true;
        if(cur>target){
            return solve(mat,pivotX,top,right,pivotY-1,target) || 
                   solve(mat,left,pivotY,pivotX-1,bottom,target) ||
                   solve(mat,left,top,pivotX-1,pivotY-1,target);
        }
        else if(cur<target){
            return solve(mat,pivotX+1,top,right,pivotY,target) ||
                   solve(mat,left,pivotY+1,pivotX,bottom,target) ||
                   solve(mat,pivotX+1,pivotY+1,right,bottom,target);
        }
        return true;
    }
    bool searchMatrix(vector<vector<int>> &matrix,int left,int top,int right,int bottom,int target)
    {
        if(right<left || bottom<top)
            return false;
        int pivot_x=left+(right-left)/2;
        int pivot_y=top+(bottom-top)/2;
        int cur=matrix[pivot_x][pivot_y];
        if(cur==target)
            return true;
        if(cur>target) 
        {
            return (searchMatrix(matrix,pivot_x,top,right,pivot_y-1,target) || 
            searchMatrix(matrix,left,pivot_y,pivot_x-1,bottom,target) || 
            searchMatrix(matrix,left,top,pivot_x-1,pivot_y-1,target)) ;
        }
        else
        {
            return (searchMatrix(matrix,pivot_x+1,top,right,pivot_y,target) || 
                searchMatrix(matrix,left,pivot_y+1,pivot_x,bottom,target) || 
                searchMatrix(matrix,pivot_x+1,pivot_y+1,right,bottom,target));  
        }
        return true;
    }
};