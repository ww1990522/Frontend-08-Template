class Solution {
public:
    vector<string> vr;
    vector<string> generateParenthesis(int n) {
        string str;
        fun(0,0,n*2,str);
        return vr;
    }
    void fun(int l, int r, int max, string str){
        if(l+r>=max)   vr.push_back(str);
        if(l<max/2) fun(l+1,r,max,str+"(");
        if(r<l)     fun(l,r+1,max,str+")");
    }

};