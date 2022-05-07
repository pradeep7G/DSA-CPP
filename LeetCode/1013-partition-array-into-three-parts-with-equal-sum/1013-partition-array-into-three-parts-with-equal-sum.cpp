class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        // int totalSum=accumulate(arr.begin(),arr.end(),0);
        // if(totalSum%3!=0)return false;
        // int target=totalSum/3;
        // int sum=0;
        // for(int i=0;i<arr.size();i++)
        // {
        //     sum+=arr[i];
        //     if(sum==target)
        //     {
        //         int innerSum=0;
        //         for(int j=i+1;j<arr.size();j++)
        //         {
        //             innerSum+=arr[j];
        //             if(j<arr.size()-1 && innerSum==target && (totalSum-innerSum-sum)==target)
        //                 return true;
        //         }
        //     }
        // }
        // return false;
        
        //Optimised O(n),space O(1);
        int total=accumulate(begin(arr),end(arr),0);
        int target=total/3;
        if(total%3!=0)return false;
        int parts=0,sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==target)sum=0,parts++;
            if((total!=0 && parts==2) || (total==0 && parts==3))
                return true;
        }
        return false;
    }
};