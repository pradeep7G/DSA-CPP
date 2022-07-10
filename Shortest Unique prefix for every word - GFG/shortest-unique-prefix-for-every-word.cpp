// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Trie{
  
  Trie* child[26];
  int startWith;
  int endWith;
  
  public:
  
  Trie()
  {
      fill_n(this->child, 26, nullptr);
      startWith = 0;
      endWith = 0;
  }
  
  void insert(string word)
  {
      Trie* root = this;
      
      for(char it : word)
      {
          int i = it-'a';
          
          if(!root->child[i])
            root->child[i] = new Trie();
        
        root = root->child[i];
        root->startWith++;
      }
      
      root->endWith++;
  }
  
  string find(string word)
  {
      Trie* root = this;
      string ans;
      
      for(char it : word)
      {
          ans.push_back(it);
          
          int i = it-'a';
          
          root = root->child[i];
          
          if(root->startWith == 1)
          break;
      }
      
      return ans;
  }
  
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie* root = new Trie();
        vector<string> ans;
        
        for(int i=0; i<n; i++)
        root->insert(arr[i]);
        
        for(int i=0; i<n; i++)
        ans.push_back(root->find(arr[i]));
        
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends