#include<bits/stdc++.h>
using namespace std;
void cyclicPermutation(int start,vector<int> &perm,vector<int> &array)
{
  int i=start;
  int temp=array[start];

  do {
    int next_i = perm[i];
    int next_temp = array[next_i];
    array[next_i] = temp;
    i=next_i;
    temp = next_temp;
  } while(i != start);
}
void permute(vector<int> &array,vector<int> &perm)
{
  //trivial solution would be creating an empty array and doing B[p[i]]=A[i], Time O(n),space O(n), can we reduce space complexity??
  //Time O(N), Space O(1)
  for(int i=0;i<array.size();i++)
  {
    int next=i;
    while(perm[next]>=0){
      swap(array[i],array[perm[next]]);
      int temp=perm[next];
      perm[next]-=perm.size();
      next=temp;
    }
  }
  for_each(begin(perm),end(perm),[&perm](int &x){
    x+=perm.size();
  });
}

void permuteBrute(vector<int> &array,vector<int> &perm)
{
  //Time O(N^2) Space O(1)
  for(int i=0;i<array.size();i++)
  {
    bool is_min=true;
    int j=perm[i];
    while(i!=j)
    {
      if(j < i)
      {
        is_min= false;
      }
      j=perm[j];
    }

    if(is_min)
    {
      cyclicPermutation(i,perm,array);
    }
  }
}
int main()
{
  vector<int> array={0,1,2,3},perm={3,1,0,2};
  // permute(array,perm);
  permuteBrute(array,perm);
  for(auto x:array)cout<<x<<" ";
  cout<<"\n";
}