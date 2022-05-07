#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end() //trick
using namespace std;

int main()
{
  //arrays are fixed size and vectors are dynamically sized

  vector<int> a({1, 2, 4, 3, 4, 4, 5, 5, 3, 2});
  // cout<<a[2];
  // array<int,3> b={1,2,3};
  // cout<<b[1]<<"\n";
  // cout<<binary_search(a.begin(),a.end(),3);
  // fill(a.begin(),a.end(),3);
  // cout<<a[1]<<"\n";
  // sort,min_element,max_element,reverse,rotate,upper_bound,lower_bound,binara_search,fill
  int ans = 0;

  //cpp tips and tricks

  //1)all(vec) user defined macro, one can also represent x.begin()+1,x.end() as 1+all(x), cox begin(x)+1,end(x) == 1+all(x);

  //2)std::unqiue, unique(all(x)) only removes consecutive duplicates and returns end of the resulting vector, generally to make a vector unique (no consecutive dups), we just resize it , vec.resize(unique(all(vec))-begin(vec))
  // a.resize(unique(all(a))-begin(a));
  // for_each(all(a),[&](int x){
  //     cout<<x<<" ";
  // });
  // cout<<"\n";

  //3) std::fill, fill(all(vec),1),

  //4) std::iota - to fill consecutinve numbers
  // iota(all(a),2);
  // for_each(all(a),[&](int x){
  //     cout<<x<<" ";
  // });
  // cout<<"\n";

  //5) user defined nxt() - int nxt(){int m;cin>>m;return m;}
  //6)std::generate - if you want to fill a range by its calls, instd of writing for loop, you can use generate to fill , ex u can use rand() instd of nxt() to fill with rand nums.

  // int n=nxt();
  // vector<int> a(n);
  // generate(all(x),nxt());
  //Bonus: - iota_n,fill_n,generate_n takes 2nd argument as size instd of end pointer , generate(begin(vec),n,nxt())

  //7) std::rotate - if we k=1 v can do shift by 1 easity but when k>1 it becomes time taking. soo.....
  //rotate(begin(vec),begin(vec)+k,end(vec)) //shift by k.

  //8) std::merge - to merge to array, be careful about size of the vector you are storing the merged vector
  //    merge(all(vec1),all(vec2),begin(mergedVec));

  //9) create a set from a vector
  // set<int> s(all(a));
  // vector<int> s(all(a)); works with all(a) or solely vector<int> s(a)
  // auto it=s.begin();
  // for(;it!=s.end();it++)cout<<*it<<" ";cout<<"\n";

  //10) map ,multimap,set,multiset.count() return count, for set and map, s.count(key) return 1, for others return count
  //   s.count(key) instead s.find(key)!=s.end()

  //11) check if an elmnt occurs in a sorted sequence ,         binary_search(all(vec),key) returns bool;

  //12) partition point, returns first iterator of a vector where predicate p(x) fails, ex:- true,true,true,false,true, returns iterator of that position, begin(vec)+3;

  //13) cast bool, simplest cast to bool operator is !!.       if(!!a[i][j]==true)

  //14) cout<<bitset<size>(n)<<"\n"; print binary rprsntion of a number

  //15) write lambda type deductin,                             auto choose=[&](int n) -> long long {                                                                                                               };
  //16) use variables inside if                                 if(int x=nxt(); isGood(x)){ use(x);};

  //17) the smallest element from a,b,c,d...
  // cout<<min({3,4,-1,-5})<<"\n";
  //   cout<<*min_element(all(vector<int>({3,4,-1,-5})))<<"\n";

  //18) make_pair(x,y) or {x,y} to pair elements x,y

  //19) tuple<type1,type2,type3> t;                             tuple<int,int,char> t;                                  t={1,2,'a'}; get<2>(t); // to get a value from the tuple

  //20) __builtin_clz(x) - count leading zeros                  __builtin_ctz(x) - count trailing zeros                 __builtin_popcount(x) - count no.of ones                __builtin_ffs(x) - returns 1+least significant 1 bit of x;

  //21)
}
