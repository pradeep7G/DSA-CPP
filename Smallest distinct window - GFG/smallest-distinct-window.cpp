// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int> mp,mp2;
        int cnt=0;
        int n=str.length();
        for(auto c:str)
            mp[c]++;
        int len=mp.size();
        int left=0,right=0,ans=INT_MAX;
        while(left<n && right<n){
            char rightchar=str[right];
            if(mp[rightchar]>0){
                if(mp2[rightchar]==0){
                    cnt++;
                }
                mp2[rightchar]++;
                
            }
            if(cnt>=len){
                ans=min(ans,right-left+1);
            }
            //shrink the window
            while(mp2.size()>=len && left<n){
                char leftchar=str[left];
                if(mp2[leftchar])
                {
                    mp2[leftchar]--;
                    if(mp2[leftchar]==0){
                        cnt--;
                        mp2.erase(leftchar);
                    }
                    ans=min(ans,right-left+1);
                }
                left++;
            }
            right++;
        }
        if(ans==INT_MAX)
         return -1;
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends