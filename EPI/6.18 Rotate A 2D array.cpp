#include<bits/stdc++.h>
using namespace std;
//Time O(N^2) Space O(1)
void rotate2DArray(vector<vector<int>> &mat){
  //do 4 way exchange, 4way swapping
  int size=mat.size()-1;
  for(int i=0;i<(mat.size()/2);i++){
    for(int j=i; j<size-i;j++)
    {
      int temp1=mat[i][j];
      int temp2=mat[j][size-i];
      int temp3=mat[size-i][size-j];
      int temp4=mat[size-j][i];
      mat[i][j]=temp4;
      mat[j][size-i]=temp1;
      mat[size-i][size-j]=temp2;
      mat[size-j][i]=temp3;
    }
  }
}
int main(){
  vector<vector<int>> array={{1,2,3},{4,5,6},{7,8,9}};
  // vector<int> spiralOrder = spiralOrdering(array);
  rotate2DArray(array);
  for(auto x:array){
    for(auto y:x)
      cout<<y<<" ";
    cout<<"\n";
  }
  cout<<"\n";
}