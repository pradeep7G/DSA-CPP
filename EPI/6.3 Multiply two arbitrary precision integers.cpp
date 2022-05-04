#include<bits/stdc++.h>
using namespace std;
//Time O(size of v1 * v2) Space: O(size of v1 + v2)
vector<int> multiply(vector<int> v1,vector<int> v2)
{
  int sign = v1.front()<0 ^ v2.front()<0 ? -1 : 1;
  v1.front()=abs(v1.front()),v2.front()=abs(v2.front());
  vector<int> ans(v1.size() + v2.size(),0);

  for(int i=v1.size()-1;i>=0;i--)
  {
    for(int j=v2.size()-1;j>=0;j--)
    {
      ans[i+j+1]+=v1[i]*v2[j];
      ans[i+j]+=ans[i+j+1]/10;
      ans[i+j+1]%=10;
    }
  }
  //remove leading zeros, use find_if_not and form new result without leading zeroes
  ans = {find_if_not(ans.begin(),ans.end(),[&](int a){return a==0;}),ans.end()};
  if(ans.empty())
  return {0};
  ans.front()*=sign;
  return ans;
}
int main()
{
    vector<int> v1={1,2,3},v2={1,2,3};
    auto ans=multiply(v1,v2);
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";
}