#include<bits/stdc++.h>
using namespace std;

//in a single pass, swapping method, Time: O(N), Space: O(1)
void dutchPartition(vector<int> &array){

  // 1,0,2,2,1,0,1 --> 0,0,1,1,1,2,2

  int smaller=0,larger=array.size()-1,equal=0,len=array.size()-1;
  while(equal<larger)
  {
    if(array[equal]<1)
    {
      swap(array[smaller++],array[equal++]);
    }
    else if(array[equal]==1)
    {
      equal++;
    }
    else
    {
      swap(array[larger--],array[equal]);
    }
  }

}

int main(){
  vector<int> array={1,0,2,2,1,0,1};
  dutchPartition(array);
  for(auto x:array)
  cout<<x<<" ";
  cout<<"\n";
}