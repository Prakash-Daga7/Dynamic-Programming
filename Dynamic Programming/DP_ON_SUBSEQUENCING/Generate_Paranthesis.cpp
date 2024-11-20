/*
  https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string>v;
        string op="";
        solve(open,close,op,v);
        return v;
    }
    void solve(int open,int close,string op,vector<string>&v)
    {
        if(open==0 && close==0) //there is answer ( base case)
        {
            v.push_back(op);
            return;
        }
        if(open!=0) // there is always open paranthesis choice
        {
            string ans1=op;
            ans1.push_back('(');
            solve(open-1,close,ans1,v);
        }
        if(close>open)
        {   string ans2=op;
            ans2.push_back(')');
            solve(open,close-1,ans2,v);
        }

    }

};