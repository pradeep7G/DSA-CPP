// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //10 ---> 50 , find num of elements less than mid1 , if nelems < k,left= mid1+1 else right-mid1-1;
    // we will stop at right value which is kth smallest and exists in the matrix;
    
    // int l=mat[0][0],r=mat[n-1][n-1];
    // while(l<=r){
    //     int mid1=l+(r-l)/2;
    //     int count=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int low=0,high=n-1;
    //         while(low<=high)
    //         {
    //             int mid=low+(high-low)/2;
    //             if(mat[i][mid]<=mid1){
    //                 low=mid+1;
    //             }
    //             else{
    //                 high=mid-1;
    //             }
    //         }
    //         count+=low;
    //     }
    //     if(count<k)l=mid1+1;
    //     else
    //         r=mid1-1;
    // }
    // return l;
    
    int l=0,r=10000;
    while(l<=r){
        int mid1=l+(r-l)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=(upper_bound(mat[i],mat[i]+n,mid1)-mat[i]);
        }
        if(count<k)
        l=mid1+1;
        else
        r=mid1-1;
    }
    return l;
}
