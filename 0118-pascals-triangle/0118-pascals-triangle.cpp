class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i  = 1;i<=numRows;i++){
            vector<int>ds;
            int res = 1;
            ds.push_back(res);
            for(int col = 1;col<i;col++){
                res = res*(i-col);
                res = res/(col);
                ds.push_back(res);
            }
            ans.push_back(ds);
        }
      return ans;
    }
};