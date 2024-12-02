#include <vector> 
using namespace std; 

class Solution {
  public:
    vector<int> findArray(int n, int k, vector<vector<int>> &ops) {
        vector <int> queries_beginning(n + 1), queries_ending(n + 1); 
        for(int i = 0; i < ops.size(); i++)
        {
            int left = ops[i][0] - 1, right = ops[i][1] - 1;
            int value = ops[i][2];
            queries_beginning[left] ^= value; 
            queries_ending[right] ^= value;
        }
        
        vector <int> A(n); 
        for(int i = 0; i < n; i++)
        {
            A[i] ^= queries_beginning[i];
            if(i > 0)
            {
                A[i] ^= A[i - 1];
            }
            
            A[i] ^= queries_ending[i];
        }
        
        return A;
    }
};
