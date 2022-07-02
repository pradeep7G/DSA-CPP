class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        int i=0,j=0,h=1;
         int ans=0;
        for(h=1;h<=26;h++){
            int arr[26]={0};
            int unique=0,notlessthank=0;
            j=0,i=0;
            while(j<n)
            {
                if(unique<=h){
                    int idx=s[j]-'a';
                     if(arr[idx]==0)
                         unique++;
                     arr[idx]++;
                     if(arr[idx]==k)
                         notlessthank++;
                     j++;
                }
                else{
                    int idx=s[i]-'a';
                    if(arr[idx]==k)
                        notlessthank--;
                    arr[idx]--;
                    if(arr[idx]==0)
                        unique--;
                    i++;
                }
                if(unique==h && notlessthank==unique){
                    ans=max(ans,j-i);
                }
             }
        }
        return ans;
        
    }
};