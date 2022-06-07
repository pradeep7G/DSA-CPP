// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
        // binary search over 0 ---> 2000, find teh right value which is the n/2th smallest element in the whole matrix
        //find number of smallest elements,count: less than mid
        
        int l=1,h=2000,n=(r*c)/2;
        while(l<=h){
            int mid=l+(h-l)/2;
            int count=0;
            for(int i=0;i<r;i++)
            {
                count+=(upper_bound(begin(mat[i]),end(mat[i]),mid) - mat[i].begin());
            }
            if(count<=n)
             l=mid+1;
            else
             h=mid-1;
        }
        return l;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends