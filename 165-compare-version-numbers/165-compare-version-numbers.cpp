class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        long long v1=0,v2=0;
        int n1=ver1.length();
        int n2=ver2.length();
        int i=0,j=0;
        for(i=0,j=0;i<n1 && j<n2;){
            v1=0,v2=0;
            while(i<n1 && isdigit(ver1[i])){
                v1=v1*10 + (ver1[i]-'0');
                i++;
            }
            while(j<n2 && isdigit(ver2[j])){
                v2=v2*10 + ver2[j]-'0';
                j++;
            }
            if(v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
            else
                i++,j++;
        }
        if(i<n1 && j>=n2)
        {
            while(i<n1)
            {
                v1=0;
                 while(i<n1 && isdigit(ver1[i])){
                    v1=v1*10 + (ver1[i]-'0');
                    i++;
                 }
                i++;
                 if(v1!=0)
                     return 1;
            }
            
        }
        else if(i>=n1 && j<n2)
        {
            while(j<n2)
            {
                v2=0;
               while(j<n2 && isdigit(ver2[j]))
               {
                v2=v2*10 + ver2[j]-'0';
                j++;
               }
                j++;
                 if(v2!=0)
                     return -1;
            }
        }
        return 0;
    }
};