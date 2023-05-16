class Solution {
public:
    string reverseVowels(string s) {
        string ans;
       for(int i =s.size()-1;i>=0;i--){
           if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||
             s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
           ans.push_back(s[i]);   
        }
        int res = 0;
     for(int i =0;i<s.size();i++)
     {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||  s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
      {     s[i] = ans[res];
         res++;
     }
         
     }
        return s;
    }
};