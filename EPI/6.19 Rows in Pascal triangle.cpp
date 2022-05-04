#include <bits/stdc++.h>
using namespace std;

//Time: O(n(n+1)/2)~=O(n^2), Space: O(n^2)
vector<vector<int> > pascalTriangle(int numRows)
{
  vector<vector<int> > pascalTriangle;
  for (int i = 0; i < numRows; i++)
  {
    vector<int> currRow;
    for (int j = 0; j <= i; j++)
    {
      currRow.push_back(j > 0 && j < i ? pascalTriangle.back()[j - 1] + pascalTriangle.back()[j] : 1);
    }
    pascalTriangle.push_back(currRow);
  }
  return pascalTriangle;
}
int main()
{
  auto ans=pascalTriangle(50);
  for(auto x:ans){
  for(auto y:x)
  cout<<y<<" ";
  cout<<"\n";
  }
  return 0;
}