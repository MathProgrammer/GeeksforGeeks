class Solution {
  public:
    int findMaxX(int n) 
    {
        int bit = 0; 
        while( (1 << bit) <= n)
        {
            bit++;
        }
        
        bit--;
        return bit;
    }
};