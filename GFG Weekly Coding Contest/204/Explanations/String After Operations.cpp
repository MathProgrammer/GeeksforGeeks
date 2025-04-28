#include <vector> 

using namespace std; 

class Solution 
{
  public:
    string processString(string &S) 
    {
        const int NO_OF_ALPHABETS = 26; 
        vector <vector <int> > position(NO_OF_ALPHABETS); 
        for(int i = 0; i < S.size(); i++)
        {
            position[S[i] - 'a'].push_back(i);
        }
        
        vector <char> final_position(S.size(), '$');
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(position[alpha].size() == 0)
            {
                continue;
            }
            
            if(position[alpha].size()%2 == 1)
            {
                int survivor = (position[alpha].size() == 1 ? 
                    position[alpha][0] : 
                    position[alpha][position[alpha].size() - 2] );
                    
                final_position[survivor] = 'a' + alpha;
            }
            else 
            {
                int survivor_1 = (position[alpha].size() == 2 ? 
                    position[alpha][position[alpha].size() - 2] : 
                    position[alpha][position[alpha].size() - 3]);
                int survivor_2 = position[alpha].back(); 
                
                final_position[survivor_1] = 'a' + alpha;
                final_position[survivor_2] = 'a' + alpha;
            }
        }
        
        string answer; 
        for(int i = 0; i < S.size(); i++)
        {
            if(final_position[i] != '$')
            {
                answer += final_position[i];
            }
        }
        
        return answer;
    }
};