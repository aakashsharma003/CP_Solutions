class Solution {
public:
    int minimizedStringLength(string s) {
        //just count unique characters in the string becz same wale remove ho jayenge
        unordered_map<int,int>mp;
        for(auto ch: s){
            mp[ch]++;
        }
        return mp.size();
    }
};