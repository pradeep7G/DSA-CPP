class Solution {
public:
    //MIN STEPS TO MAKE STRINGS EQUAL
    int solve(string &original,string kth){
        //Attention : adjacent swaps
        int n=original.size();
        int i=0,j=0;
        int res=0;
        while(i<n){
            j=i;
            while(j<n and original[j]!=kth[i])j++;
            while(i<j){
                swap(original[j],original[j-1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
    int minSteps(string original,string kth){
        int size=original.length();
        int i=0,j=0;
        int res=0;
        while(i<size){
            j=i;
            while(j<size && original[j]!=kth[i])j++;
            while(i<j){
                swap(original[j],original[j-1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
    int getMinSwaps(string num, int k) {
        //classic
        string kth=num;
        while(k--)
            next_permutation(begin(kth),end(kth));
        return solve(num,kth);
    }
};