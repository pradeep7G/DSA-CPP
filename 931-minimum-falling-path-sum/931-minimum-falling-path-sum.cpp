class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> tmp(n);
        for(int i=0;i<n;i++)
            tmp[i]=matrix[n-1][i];
        vector<int> cur(n);
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=tmp[j];
                int left=1e9;
                if(j-1>=0)
                    left=tmp[j-1];
                int right=1e9;
                if(j+1<n)
                    right=tmp[j+1];
                cur[j]=matrix[i][j]+min({left,right,down});
            }
            tmp=cur;
        }
        return *min_element(begin(tmp),end(tmp));
    }
};