class Solution {
  public:
    int is_bit_set(long long n, int bit)
    {
        return ( (n&(1LL << bit)) != 0 );
    }
    
    long long count(long long n)
    {
        int bit_count = 0;
        long long total = 0;
        const int MAX_BIT = 63, MOD = 1e9 + 7;
        for(int bit = MAX_BIT; bit > 0; bit--)
        {
            if(is_bit_set(n, bit))
            {
                int remaining_bits = bit;
            
                total += (1LL << (remaining_bits - 1));
                total %= MOD;
                
                bit_count++;
            }
        }
        
        if(bit_count%2 == 1 && n%2 == 1)
        {
            total++;
        }
        
        return total;
    }
    
    int countNumbers(long long l, long long r) 
    {
        const int MOD = 1e9 + 7;
        return (count(r + 1) - count(l) + MOD)%MOD;
        
    }
};