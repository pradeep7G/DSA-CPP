class Solution {
public:
    string getPermutation(int n, int k) {
        // can use c++'s next_permutation function or you can do the real way,
        string res="";
        string ans="";
        for(int i=1;i<=n;i++){
            ans+=(to_string(i));
        }
        vector<int> factorial(n+1);
        factorial[0]=1;
        for(int i=1;i<=n;i++){
            factorial[i]=factorial[i-1]*i;
        }
        k--;
        for(int i=1;i<=n;i++){
            int index=(k/factorial[n-i]);
            res+=ans[index];
            ans=ans.substr(0,index)+ans.substr(index+1);
            k-=(index*factorial[n-i]);
        }
        return res;
    }
};