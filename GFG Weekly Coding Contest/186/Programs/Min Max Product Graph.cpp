class Solution 
{
  public:
    int minmaxDifference(long long n) 
    {
        if(n <= 2)
        {
            return 0;
        }
        
        const int MOD = 1e9 + 7;
        
        long long component_3s = n/3;
        
        long long max_edges = (component_3s*3)%MOD;
        long long min_edges = (component_3s*2)%MOD;
        
        if(n%3 == 1)
        {
            //Complete 4-component
            max_edges += 3; 
        }
        else if(n%3 == 2)
        {
            //Break any 3-component to get 2 2-components
            max_edges++; 
            min_edges++;
        }
        
        return (max_edges - min_edges + MOD)%MOD;
    }
};