class Solution {
public:
    // time complexity ->O(2*n*m) ,S.C->O(n)+O(m)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
       // int col[m] = {0} -> matrix[0][...]
       // int row[n] = {0} -> matrix[...][0] 
        int colmn = 1;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {   
                if(matrix[i][j] == 0)
                {
                    // mark row at indx i
                    matrix[i][0] = 0;
                    //mark col at indx j
                    if(j != 0)
                    matrix[0][j] = 0;
                    else
                     colmn = 0;   
                }
             }
         }
        for(int i =1;i<n;i++)
        {
           for(int j =1;j<m;j++)
           {
               if(matrix[i][j] != 0)
               {  //check for row and col is anyone 0 or not 
                   if(matrix[0][j] == 0 || matrix[i][0] == 0)
                       matrix[i][j] = 0;
                       
               }
           } 
        }
        if(matrix[0][0] == 0)
        {
          for(int j =0;j<m;j++)
            matrix[0][j] = 0;
        }   
        if(colmn == 0)
        {
          for(int j =0;j<n;j++)
            matrix[j][0] = 0;
        }    
    
        return;
    }
};