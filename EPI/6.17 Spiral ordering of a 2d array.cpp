#include<bits/stdc++.h>
#include<array>
using namespace std;
void ComputeLaterInClockWise(vector<vector<int>> &array,int offset,vector<int> &spiralOrdering){
  if(offset == array.size()-offset-1){
    spiralOrdering.emplace_back(array[offset][offset]);
    return;
  }
  for(int j=offset;j<array.size()-offset-1;j++)
  {
    spiralOrdering.push_back(array[offset][j]);
  }
  for(int i=offset;i<array.size()-offset-1;i++)
  {
    spiralOrdering.push_back(array[i][array.size()-offset-1]);
  }
  for(int j=array.size()-offset-1;j>offset;j--)
  {
    spiralOrdering.push_back(array[array.size()-offset-1][j]);
  }
  for(int i=array.size()-offset-1;i>offset;i--)
  {
    spiralOrdering.push_back(array[i][offset]);
  }
}
vector<int> spiralOrdering(vector<vector<int>> &array){
  vector<int> spiralOrdering;
  for(int offset=0;offset<ceil(0.5 * array.size());offset++)
  {
    ComputeLaterInClockWise(array,offset,spiralOrdering);
  }
  return spiralOrdering;
}

 vector<int> singlePassSpiralOrdering(vector<vector<int>> &arr){
  vector<int> spiralOrdering;
  const array<array<int,2>,4> kshift={{{0,1},{1,0},{0,-1},{-1,0}}};
  int dir=0,x=0,y=0;
  for(int i=0;i<arr.size()*arr.size();i++)
  {
    spiralOrdering.push_back(arr[x][y]);
    arr[x][y]=0;
    int next_x=x+kshift[dir][0];int next_y=y+kshift[dir][1];
    if(next_x < 0 || next_y<0 || next_x>=arr.size() || next_y>=arr.size() || arr[next_x][next_y]==0)
    {
      dir=(dir+1)%4;
      next_x=x+kshift[dir][0],next_y=y+kshift[dir][1];
    }
    x=next_x,y=next_y;
  }
  return spiralOrdering;
}

int main(){
  vector<vector<int>> array={{1,2,3},{4,5,6},{7,8,9}};
  // vector<int> spiralOrder = spiralOrdering(array);
  vector<int> spiralOrder = singlePassSpiralOrdering(array);
  for(auto x:spiralOrder)cout<<x<<" ";
  cout<<"\n";
}