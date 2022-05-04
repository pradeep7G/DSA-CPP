#include<bits/stdc++.h>
using namespace std;
int deleteDups(vector<int> &array){
  int len = array.size();
  if(array.empty())
  return 0;
  int writeIndex=1;
  for(int i=1;i<len;i++)
  {
    if(array[writeIndex-1]!=array[i])
    {
      array[writeIndex++]=array[i];
    }
  }
  return writeIndex;
}
int main(){
  vector<int> array = {2,3,5,5,7,11,11,11,12};
  cout<<deleteDups(array)<<"\n";
} 