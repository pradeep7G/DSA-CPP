class Solution {
public:
    int optimised(string s){
        int count=0,left=0,right=0,n=s.length();
        int ar[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
            if(s[i]=='a')
                ar[0]=i;
            else if(s[i]=='b')
                ar[1]=i;
            else
                ar[2]=i;
            if(ar[0]==-1 || ar[1]==-1 || ar[2]==-1)
                continue;
            count+=min({ar[0],ar[1],ar[2]})+1;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        return optimised(s);
        int ans=0,n=s.length(),left=0,right=0;
        unordered_map<char,int> mp;
        vector<int> v;
        for(;right<n;right++){
            char rightchar=s[right];
            mp[rightchar]++;
            while(mp.size()==3){
                v.push_back(right);
                char leftchar=s[left++];
                mp[leftchar]--;
                if(mp[leftchar]==0)
                    mp.erase(leftchar);
            }
        }
        for(auto i:v)
            ans+=(n-i);
        return ans;
    }
};