// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int find(int r,int c,int i,int j,string &target,int index,vector<vector<char>> &mat){
        if(index>=target.size())
         return 0;
        int found=0;
        if(i<r && j<c && i>=0 && j>=0 && target[index]==mat[i][j]){
            char match=target[index];
            index++;
            mat[i][j]='0';
            if(index>=target.size()){
                found++;
            }
            found+=find(r,c,i+1,j,target,index,mat);
            found+=find(r,c,i,j+1,target,index,mat);
            found+=find(r,c,i-1,j,target,index,mat);
            found+=find(r,c,i,j-1,target,index,mat);
            mat[i][j]=match;
        }
        return found;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int r=mat.size();
        int c=mat[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                count+=find(r,c,i,j,target,0,mat);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends