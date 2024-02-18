class Solution {
  public:
  
    int max_4(int a, int b, int c, int d)
    {
        return max(max(a, b), max(c, d));
    }
    
    int collectingCoins(int N, vector<vector<int>> &Coins) 
    {
        int maximum_coins = 0; 
        unordered_map <int, int> row_frequency, column_frequency, diagonal_frequency, anti_diagonal_frequency; 
        for(int i = 0; i < Coins.size(); i++)
        {
            int r = Coins[i][0], c = Coins[i][1];
            int diagonal = r + c, anti_diagonal = r - c; 
            
            row_frequency[r]++; 
            column_frequency[c]++; 
            diagonal_frequency[diagonal]++; 
            anti_diagonal_frequency[anti_diagonal]++;
            
            int maximum_with_this_coin = max_4(row_frequency[r],
                column_frequency[c], 
                diagonal_frequency[diagonal],
                anti_diagonal_frequency[anti_diagonal]);
            
            maximum_coins = max(maximum_coins, maximum_with_this_coin);
        }
        
        return maximum_coins;
    }
};
