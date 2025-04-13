#include <algorithm>
#include <stack> 
#include <vector>

using namespace std; 

class Solution {
  public:
    int minOperation(vector<vector<int> >& M) 
    {
        int rows = M.size(), columns = M[0].size();
        vector <int> columns_sum(columns + 1); 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                columns_sum[c] += M[r][c];
            }
        }
        
        const int oo = 1e9;
        int min_operations = oo;
        for(int r = 0; r < rows; r++)
        {
            int operations_for_this_row = 0; 
            for(int c = 0; c < columns; c++)
            {
                int remaining_column_sum = columns_sum[c] - M[r][c]; 
                operations_for_this_row += abs(remaining_column_sum - M[r][c]);
            }
            
            min_operations = min(min_operations, operations_for_this_row);
        }
        
        return min_operations;
    }
};