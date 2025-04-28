#include <vector> 

using namespace std;

class Solution 
{
  public:
    long long totDiff(string &S, string &T) 
    {
        long long total = 0;
        
        const int NO_OF_ALPHABETS = 26; 
        vector <vector <int> > positions(NO_OF_ALPHABETS);
        for(int i = 0; i < T.size(); i++)
        {
            positions[T[i] - 'a'].push_back(i);
        }
        
        for(int i = 0; i < S.size(); i++)
        {
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                for(int position = 0; position < positions[alpha].size(); position++)
                {
                    int j = positions[alpha][position];
                    long long possible_lefts = min(i + 1, j + 1);
                    long long possible_rights = min(S.size() - i, T.size() - j);
                    long long substrings_with_this_pair = possible_lefts*possible_rights;
                    
                    total += abs(S[i] - alpha - 'a')*substrings_with_this_pair;
                }
            }
        }
        
        return total;
    }
};