//Detect Capital

class Solution {
public:
   bool detectCapitalUse(string s) {
        int sum=0,n=s.length();   //sum --> count of 'a' to 'z'
        for(int i=1;i<n;++i) if(s[i]>=97) ++sum;
        return sum==n-1 || (sum==0 && s[0]<=90);
   }
        
  
};
