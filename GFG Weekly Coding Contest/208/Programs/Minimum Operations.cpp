#include <vector> 
#include <algorithm> 
#include <map>
using namespace std; 

class Solution {
  private: 
    int get_operations_even(vector <int> &A, int k)
    {
        int operations = 0; 
        for(int i = 1; i < A.size(); i+=2)
        {
            operations += (A[i] - A[i - 1])/k;
        }
        
        return operations;
    }

    int get_operations_odd(vector <int> &A, int k)
    {
        vector <int> prefix(A.size()); 
        for(int i = 1; i < A.size(); i++)
        {
            prefix[i] = (A[i] - A[i - 1])/k + (i == 1 ? 0 : prefix[i - 2]);
        }
        
        vector <int> suffix(A.size());
        for(int i = A.size() - 2; i >= 0; i--)
        {
            suffix[i] = (A[i + 1] - A[i])/k + (i + 2 == A.size() ? 0 : suffix[i + 2]);
        }

        int answer = 1e9;
        for(int i = 0; i < A.size(); i += 2)
        {
            int answer_here = (i == 0 ? 0 : prefix[i - 1]) + 
                            (i + 1 == A.size() ? 0 : suffix[i + 1]);
                            
            answer = min(answer_here, answer);
        }

        return answer;
    }

    int get_operations(vector <int> &A, int k)
    {
        sort(A.begin(), A.end());
        
        return A.size()%2 == 1 ? 
            get_operations_odd(A, k) : 
            get_operations_even(A, k);
    }
    
  public:
    int minOperations(vector<int> &A, int k) 
    {
        map <int, int> frequency; 
        vector <vector <int> > elements(k);
        for(int i = 0; i < A.size(); i++)
        {
            int mod = A[i]%k;
            frequency[mod]++;
            elements[mod].push_back(A[i]);
        }
        
        int odd_frequency_moduli = 0;
        for(int i = 0; i < k; i++)
        {
            odd_frequency_moduli += (frequency[i]%2 == 1);
        }
        
        if(odd_frequency_moduli > 1)
        {
            return -1;
        }
        
        int operations = 0; 
        for(int i = 0; i < k; i++)
        {
            operations += get_operations(elements[i], k);
        }
        
        return operations;
    }
};