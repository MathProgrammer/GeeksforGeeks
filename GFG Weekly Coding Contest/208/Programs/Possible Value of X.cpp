class Solution {
  private: 
   int is_bit_set(int n, int bit)
   {
       return ( (n&(1 << bit)) != 0 );
   }
   
  public:
    int ValueX(int a, int b, int c) {
        // code here
        const int MAX_BIT = 30; 
        int x = 0;
        for(int bit = MAX_BIT; bit >= 0; bit--)
        {
            if(!is_bit_set(c, bit))
            {
                if(is_bit_set(b, bit) && is_bit_set(a, bit))
                {
                    return -1;
                }
            }
            else 
            {
                if(!is_bit_set(b, bit) || !is_bit_set(a, bit))
                {
                    x |= (1 << bit);
                }
            }
        }
        
        return x;
    }
};