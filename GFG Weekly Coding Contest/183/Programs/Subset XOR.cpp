#include <vector> 
using namespace std; 

class Solution {
  public:
    vector<int> subsetXOR(int n) 
    {
        int excluded_number = 0;
        switch(n%4)
        {
            case 0 : excluded_number = 0; 
                     break;
                     
            case 1 : excluded_number = n^1;
                     break;
                     
             case 2 : excluded_number = (n + 1)^n;
                     break; 
            
            case 3 : excluded_number = n;
        }
        
        vector <int> answer; 
        for(int i = 1; i <= n; i++)
        {
            if(i == excluded_number)
            {
                continue;
            }
            
            answer.push_back(i);
        }
        
        return answer;
    }
};