class Solution {
public:
    int longestValidParentheses(string s) {
       
        stack<int> sc;
        sc.push(-1);
        int max_len = 0;
        int i = 0;
        for(auto c:s)
        {
            if(c==')')
            {
                sc.pop();  
                if(sc.empty())
                {
                    sc.push(i);
                }                
                else
                {
                    max_len = max(max_len,i-sc.top());
                }
            }
            else
            {
                sc.push(i);      
            }

            i++;
        }

        return max_len;
    }

};