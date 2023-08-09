class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;
        string str;
      
        for(int i =0;i<s.size();i++){
            if(!stk.empty() && s[i] == stk.top()){
                stk.pop();
            }
            else
            stk.push(s[i]);
        }
        
        while(!stk.empty()){
            str.push_back(stk.top());
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};