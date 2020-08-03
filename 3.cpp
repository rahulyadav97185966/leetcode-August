// Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() > 1){
            string s1 = "";
            for(int i=0;i<s.length();i++){
                if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                    s1 += s[i];
                }
            }
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            return isPalindrome1(s1);
        }
        else{
            return true;
        }
    }
    bool isPalindrome1(string str) 
    { 
            int l = 0; 
            int h = str.length() - 1; 
            while (h > l) 
            { 
                if (str[l++] != str[h--]) 
                { 
                    return false; 
                } 
            } 
            return true;
    } 
};
