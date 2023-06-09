class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char res = 126;
        int ans = 126;
        for(int i =0;i<n;i++){
            if((int)letters[i] > (int)target )
                res = letters[i];
            ans = min((int)res,ans);
        }
        if(res == 126)
        return letters[0];
        char temp = (char)ans;
        return temp;
    }
};