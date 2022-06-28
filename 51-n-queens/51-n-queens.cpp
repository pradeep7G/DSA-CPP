class Solution {
public:
    vector<vector<string>> res;
    bool is_safe(int r,int c,int n,vector<vector<bool>> &board,vector<bool> &left,vector<bool> &right,vector<bool> &row){
        if(row[r]==false && left[r+c]==false && right[r-c+n+1]==false){
            return true;
        }
        return false;
    }
    void make_sol(int n,vector<vector<bool>> &board){
        vector<string> ret;
        for(int i=0;i<n;i++){
            string row="";
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    row+="Q";
                }
                else{
                    row+=".";
                }
            }
            ret.push_back(row);
        }
        res.push_back(ret);
        return ;
    }
    void solve(int c,int n,vector<vector<bool>> &board,vector<bool> &left,vector<bool> &right,vector<bool> &row){
        if(c>=n){
            make_sol(n,board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(is_safe(i,c,n,board,left,right,row)){
                row[i]=true;
                left[i+c]=true;
                right[i-c+n+1]=true;
                board[i][c]=true;
                solve(c+1,n,board,left,right,row);
                board[i][c]=false;
                row[i]=false;
                left[i+c]=false;
                right[i-c+n+1]=false;
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<bool> left(25,false);
        vector<bool> right(25,false);
        vector<bool> row(12,false);
        vector<vector<bool>> board(n,vector<bool>(n,false));
        solve(0,n,board,left,right,row);
        return res;
    }
};