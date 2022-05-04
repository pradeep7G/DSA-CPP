#include<bits/stdc++.h>
using namespace std;

//Time: O(NloglogN) , Space O(N) space taken to store whether is prime or not.
vector<int> enumerate(int n)
{
  //enumerate all prime numbers between 1 and n
  vector<int> primes;
  deque<bool> isPrime(n+1,true);
  isPrime[0]=isPrime[1]=false;  
  for(int i=2;i<n;i++)
  {
    if(isPrime[i])
    {
      primes.emplace_back(i);
      for(int j=i;j<=n;j+=i)
      {
        isPrime[j]=false;
      }
    }
  }
  return primes;
}
int main()
{
  int n=20;
  vector<int> primes=enumerate(n);
  for(auto x:primes)cout<<x<<" ";
  cout<<"\n";
}