#include<bits/stdc++.h>
using namespace std;

//Time O(N), Space O(n) space used to store best solutions for first buy ans sell
int BuyAndSellTwiceAtMost(vector<double> &array){
  int len=array.size();
  double maxTotalProfit=0;
  vector<double> firstBuyAndSell(len,0);
  double minPriceSoFar=numeric_limits<double>::max();

  for(int i=0;i<len;i++)
  {
    minPriceSoFar = min(minPriceSoFar,array[i]);
    maxTotalProfit=max(maxTotalProfit,array[i]-minPriceSoFar);
    firstBuyAndSell[i]=maxTotalProfit;
  }
  //backward pass, for each day find max profit we make 
  double maxPriceSoFar = numeric_limits<double>::min();
  for(int i=len-1;i>0;i--)
  {
    maxPriceSoFar=max(maxPriceSoFar,array[i]);
    maxTotalProfit=max(maxTotalProfit,maxPriceSoFar-array[i]+firstBuyAndSell[i-1]);
  }
  return maxTotalProfit;
}
int main(){
  // vector<int> array={310,325,275,295,260,270,290,230,255,250};
  // vector<int> array={20,10,50,100};
  vector<double> array={12,11,13,9,12,8,14,13,15};
  cout<<BuyAndSellTwiceAtMost(array)<<"\n";
}