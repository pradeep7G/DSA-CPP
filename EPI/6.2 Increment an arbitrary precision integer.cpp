#include<bits/stdc++.h>
using namespace std;
//Time O(n),Space: O(1)
void increment(vector<int> &array)
{
  //natural instinctive way
  int len=array.size()-1;
  array[len]++;
  for(int i=len;i>0 && array[i]==10;i--)
  {
    array[i]=0;array[i-1]++;
  }
  if(array[0]==10)
  {
    array[0]=0;
    array.insert(array.begin(),1);
  }
}
int main()
{
  vector<int> array={9,9,9,9,9};
  increment(array);
  for(auto x:array)cout<<x<<" ";
  cout<<"\n";
}