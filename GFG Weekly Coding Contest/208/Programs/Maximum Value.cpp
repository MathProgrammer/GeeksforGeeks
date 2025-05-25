#include <algorithm> 
#include <vector>

using namespace std; 

class Solution {
  public:
    int maximumValue(vector<int>& A) {
        sort(A.begin(), A.end()); 
        
        return 2*(A.back() - A[0]);
        
    }
};