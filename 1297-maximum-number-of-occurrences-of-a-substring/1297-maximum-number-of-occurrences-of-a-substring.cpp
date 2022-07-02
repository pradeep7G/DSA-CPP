class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> freq;
        unordered_map<char,int> mp;
        int n=s.length();
        int left=0,right=0,res=0;
        for(;right<n;right++){
         char rightchar=s[right];
         mp[rightchar]++;
         if(right<minSize-1)
             continue;
         while(right-left+1>minSize){
             if(--mp[s[left]]==0)
                 mp.erase(s[left]);
             left++;
         }
         if(right-left+1==minSize && mp.size()<=maxLetters){
             res=max(res,++freq[s.substr(left,right-left+1)]);
         }
        }
        return res;
    }
};