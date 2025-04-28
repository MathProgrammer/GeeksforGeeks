#include <vector> 

using namespace std; 

class Solution 
{
  public:
    long long minOperation(vector<int>&A) 
    {
        const int MAX_N = 1e5 + 1; 
        vector <vector <int> > indices(MAX_N); 
        for(int i = 0; i < A.size(); i++)
        {
            indices[A[i]].push_back(i);
        }
        
        long long n = A.size();
        long long total_pairs = 0;
        for(int i = 1; i <= n; i++)
        {
            total_pairs += (n - i + 1)*(i/2);
        }
        
        long long unneeded_operations = 0; 
        for(int i = 1; i < MAX_N; i++)
        {
            if(indices[i].size() < 2)
            {
                continue;
            }
            
            for(int j = 0; j < indices[i].size(); j++)
            {
                for(int k = j + 1; k < indices[i].size(); k++)
                {
                    long long left = indices[i][j], right = indices[i][k];
                    long long segments_with_this_pair = min(left + 1, n - right);
                    unneeded_operations += segments_with_this_pair;
                    
                }
            }
        }
        
        long long operations = total_pairs - unneeded_operations; 
        return operations;
    }
};