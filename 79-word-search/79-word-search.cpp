class Solution {
public:
    bool solve(int i,int j,int ind,int n,string &word,vector<vector<char>> &board){
        if(ind==n)
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]){
            return false;
        }
        char tmp=board[i][j];
        board[i][j]='#';
        bool top=false,down=false,left=false,right=false;
        top=solve(i-1,j,ind+1,n,word,board);
        down=top || solve(i+1,j,ind+1,n,word,board);
        left=down || solve(i,j-1,ind+1,n,word,board);
        right=left || solve(i,j+1,ind+1,n,word,board);
        if(top || down || left || right)
            return true;
        board[i][j]=tmp; //backtrack
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int m=board.size(),n=board[0].size();
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(solve(i,j,0,word.size(),word,board))
                   return true;
           }
       }
       return false;
    }
};