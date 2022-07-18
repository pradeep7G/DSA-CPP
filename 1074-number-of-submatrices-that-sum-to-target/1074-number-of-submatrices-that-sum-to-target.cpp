class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // 0 0, to m,n, how can we get to check submatrices sum efficiently
        //2d pref sums ; 
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> presums(m+1,vector<int>(n+1,0));
        //presums along rows
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                presums[i][j]=matrix[i-1][j-1]+presums[i][j-1];
            }
        }
        //presums along columns
        // for(int i=1;i<=m;i++){
        //     for(int j=0;j<=;j++){
        //         presums[i][j]+=presums[i-1][j];
        //     }
        // }
        int ans=0;
        unordered_map<int,int> mp;
        for(int colStart=1;colStart<=n;colStart++){
            for(int colEnd=colStart;colEnd<=n;colEnd++){
                //can be reduced to O(m) with using hashmap, same as subarray sum equals to k (previously implemented with O(m*N ^ 2)) solution so reduced it to O(n*m*m)
                int curSum=0;
                mp={{0,1}};//reassigning hashmap
                for(int rowStart=1;rowStart<=m;rowStart++){
                   curSum+=(presums[rowStart][colEnd]-presums[rowStart][colStart-1]);
                   ans+=mp[curSum-target];
                   mp[curSum]++;
                }
                
            }
        }
        return ans;
        
    }
};