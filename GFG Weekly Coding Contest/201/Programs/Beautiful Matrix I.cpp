#include <vector> 
using namespace std; 

class Solution 
{
  public:
    bool isBeauty(vector<vector<int>> &M) 
    {
        int rows = M.size(), columns = M[0].size(); 
        vector <int> column_sum(columns);
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                column_sum[c] += M[r][c];
            }
        }
        
        int good_columns = 0; 
        for(int c = 0; c < columns; c++)
        {
            for(int r = 0; r < rows; r++)
            {
                if(2*M[r][c] == column_sum[c])
                {
                    good_columns++;
                    break;
                }
            }
        }
        
        return (good_columns == columns);
    }
};