#include<bits/stdc++.h>
using namespace std;
int BuyAndSellOnce(vector<int> & array){
  //Time Complexity O(N), Space : O(1)
  int len=array.size();
  int minValSoFar=array[0],maxProfitSoFar=array[1]-array[0];
  for(int i=1;i<len;i++)
  {
    if(array[i]<minValSoFar)
    {
      minValSoFar=array[i];
    }
    else
    {
      maxProfitSoFar=max(maxProfitSoFar,array[i]-minValSoFar);
    }
  }
  return maxProfitSoFar;
}
int main(){
  // vector<int> array={310,325,275,295,260,270,290,230,255,250};
  vector<int> array={20,10,50,100};
  cout<<BuyAndSellOnce(array)<<"\n";
}