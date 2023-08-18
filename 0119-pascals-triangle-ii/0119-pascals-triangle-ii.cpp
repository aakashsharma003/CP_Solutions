class Solution {
public:
    vector<int> getRow(int row) {
          long long res = 1;
           row = row+1;
          vector<int>ds;
          ds.push_back(res);
        for(int col = 1;col<row;col++){
            res = res*(row-col);
            res = res/(col);
            ds.push_back(res);
            }
        return ds;
    }
};