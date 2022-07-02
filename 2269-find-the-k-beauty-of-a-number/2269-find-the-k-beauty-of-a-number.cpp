class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans=0;
        string str=to_string(num);
        int n=str.length();
        int pwr=pow(10,k-1);
        int digit=0;
        for(int i=0;i<n;i++){
            if(i<k-1){
                digit=digit*10 + (str[i]-'0');
                continue;
            }
            digit=digit*10 + (str[i]-'0');
            if(digit!=0 && num%digit==0)
                ans++;
            //remove left from the window
            int lastdigit=str[i-k+1]-'0';
            digit=digit-lastdigit*pwr;
        }
        return ans;
    }
};