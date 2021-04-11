class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        if(isPalindrome(s,0,len-1)) return true;
        
        for(int l=0, r=len-1; l<r; l++,r--){
            if(s[l]!=s[r]){
                if(isPalindrome(s,l+1,r) || isPalindrome(s, l, r-1))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    bool isPalindrome(string s,int l, int r){
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++; r--;
        }
        return true;
    }
};