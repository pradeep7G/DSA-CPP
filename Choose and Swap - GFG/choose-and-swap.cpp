// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string ar){
        //can only choose atmost once
       vector<int> pos(26);
       int n=ar.length();
       for(int i=0;i<26;i++)
       pos[i]=-1;
       for(int i=0;i<n;i++){
           if(pos[ar[i]-'a']==-1){
               pos[ar[i]-'a']=i;
           }
       }
       int i=0,j=0;
       for(i=0;i<n;i++){
           bool flag=false;
           for(j=0;j<ar[i]-'a';j++){
               if(pos[j]>pos[ar[i]-'a']){
                   flag=true;
                   break;
               }
           }
           if(flag)
           break;
       }
       if(i<n){
           char ch1=ar[i];
           char ch2=char(j+'a');//smallest character greater that ar[i] and pos[smallest character greater than ar[i] > pos[ar[i];
           for(int i=0;i<n;i++){
               if(ar[i]==ch1)
               ar[i]=ch2;
               else if(ar[i]==ch2)
               ar[i]=ch1;
           }
       }
       return ar;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends