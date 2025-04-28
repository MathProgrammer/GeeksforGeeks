#include <vector> 
#include <map> 

using namespace std; 

class Solution 
{
  public:
    long long countPairs(vector<int> &A) 
    {
        map <int, int> frequency; 
        long long pairs = 0;
        for(int i = 0; i < A.size(); i++)
        {
            int value = A[i] - i;
            
            pairs += 2*frequency[value];
            frequency[value]++;
        }
        
        return pairs;
    }
};