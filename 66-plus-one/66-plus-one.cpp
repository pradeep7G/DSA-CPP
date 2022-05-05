class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++;
        for(int i=digits.size()-1;i>0 && digits[i]==10;i--)
        {
            digits[i-1]+=1;digits[i]=0;
        }
        if(digits[0]==10)
           digits[0]=0, digits.insert(begin(digits),1);
        return digits;
    }
};