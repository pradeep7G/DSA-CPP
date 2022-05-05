class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
      int m=board.size(),n=board[0].size();
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              int cnt=0;
              for(int x=max(i-1,0);x<min(i+2,m);x++)
              {
                  for(int y=max(j-1,0);y<min(j+2,n);y++)
                  {
                      cnt+= board[x][y] & 1;
                  }
              }
              if(cnt==3 || cnt-board[i][j]==3){
                  board[i][j]+=2;
              }
          }
      }
        for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              board[i][j]>>=1;
          }
      }
        
    }
};