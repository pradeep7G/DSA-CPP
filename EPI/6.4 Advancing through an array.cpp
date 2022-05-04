#include<bits/stdc++.h>
using namespace std;
//Time O(n),Space O(1)
bool advanceThroughArray(vector<int> &array)
{
  int maxReach=0,lastIndex=array.size()-1;
  for(int i=0;i<=maxReach && maxReach < lastIndex;i++)
  {
    maxReach = max(maxReach,i+array[i]);
  }
  return maxReach>=lastIndex;
}
int main(){
  vector<int> array={2,4,1,1,0,0,0,0,2,3};
  cout<<advanceThroughArray(array)<<"\n";
}