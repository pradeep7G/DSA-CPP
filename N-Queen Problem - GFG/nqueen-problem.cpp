// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> result;
    bool is_safe(vector<vector<int>> &board,int i,int j){
        //check for left side in the row
        for(int c=j-1;c>=0;c--){
            if(board[i][c])
                return false;
        }
        //check for down of left diagonally
        for(int r=i+1,c=j-1;r<board.size() && c>=0;r++,c--){
            if(board[r][c])
             return false;
        }
        //check for top of left diagonally
        for(int r=i-1,c=j-1;r>=0 && c>=0;r--,c--){
            if(board[r][c])
             return false;
        }
        return true;
    }
    void solve(vector<vector<int>> &board,int col,vector<int> &sol){
        if(col>=board[0].size()){
            result.push_back(sol);
            return ;
        }
        for(int i=0;i<board.size();i++){
            if(is_safe(board,i,col)){
                board[i][col]=1;
                sol.push_back(i+1);
                solve(board,col+1,sol);
                board[i][col]=0;
                sol.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        result.clear();
        vector<int> sol;
        solve(board,0,sol);
        sort(result.begin(),result.end());
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends