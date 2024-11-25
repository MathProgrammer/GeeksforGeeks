#include <vector> 
#include <algorithm>

using namespace std; 

#define all(v) (v).begin(), (v).end()
class Solution {
  public:
    int min(int x, int y)
    {
        return (x < y ? x : y);
    }
    
    int minTime(int k, vector<int> &positions) {
        vector <int> positive, negative; 
        for(int i = 0; i < positions.size(); i++)
        {
            if(positions[i] > 0)
            {
                positive.push_back(positions[i]);
            }
            else if(positions[i] < 0)
            {
                negative.push_back(abs(positions[i]));
            }
            else 
            {
                k--;
            }
        }
        
        if(k <= 0)
        {
            return 0;
        }
        
        sort(all(positive)); 
        sort(all(negative));
        
        const int oo = 2e8;
        int time = oo;
        int only_positive = (positive.size() >= k ? positive[k - 1] : oo);
        int only_negative = (negative.size() >= k ? negative[k - 1] : oo);
        time = min(only_positive, only_negative);
        
        for(int i = 0; i < min(k, positive.size()); i++)
        {
            int remaining = k - (i + 1); 
            if(remaining <= 0 || remaining > negative.size())
            {
                continue;
            }
            int current_time = 2*positive[i] + negative[remaining - 1];
            
            time = min(time, current_time);
        }
        
        for(int i = 0; i < min(k, negative.size()); i++)
        {
            int remaining = k - (i + 1); 
            if(remaining <= 0 || remaining > positive.size())
            {
                continue;
            }
            
            int current_time = 2*negative[i] + positive[remaining - 1];
            
            time = min(time, current_time);
        }
        
        return time;
    }
};