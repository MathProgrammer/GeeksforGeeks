// User function Template for C++
#include <vector> 
using namespace std; 

class Solution {
  public:
    int longestSubsequence(vector<int>&A, int k) {
        // code here
        vector <int> longest_sequence(A.size()); 
        for(int i = 1; i < A.size(); i++)
        {
            longest_sequence[i] = longest_sequence[i - 1];
            for(int j = i - 1; j >= 0; j--)
            {
                if(abs(A[i] - A[j]) > k)
                {
                    continue;
                }
                
                int sequence_before = (j == 0 ? 0 : longest_sequence[j - 1]);
                longest_sequence[i] = max(longest_sequence[i], 2 + sequence_before);
            }
        }
        
        return longest_sequence.back();
    }
};