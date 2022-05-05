class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> kshift={{0,1},{1,0},{0,-1},{-1,0}};
        if(n==1)
            return {{1}};
        vector<vector<int>>mat(n,vector<int>(n,-1));
        int x=0,y=0,val=1,dir=0;
        for(int i=0;i<n*n;i++)
        {
            if(mat[x][y]==-1)
            {
                mat[x][y]=val;val++;
                int new_x=x+kshift[dir][0],new_y=y+kshift[dir][1];
                if(new_x>=n || new_y>=n || new_x<0 || new_y < 0 || mat[new_x][new_y]!=-1)
                {
                    dir=(dir+1)%4;
                    new_x=x+kshift[dir][0];new_y=y+kshift[dir][1];
                }
                x=new_x;y=new_y;
            }
            else
            {
                dir=(dir+1)%4;
                x=x+kshift[dir][0];y=y+kshift[dir][1];
            }
        }
        return mat;
    }
};