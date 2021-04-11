class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  
            return false;

        map<char,int> mc;
        for(auto c : s){
            mc[c] = mc.count(c)>0 ? mc[c]+1 : 1;
        }
        for(auto ct : t){
            if(mc[ct]>0)  
                mc[ct]--;
            else    
                return false;
        }
        return true;
    }
};