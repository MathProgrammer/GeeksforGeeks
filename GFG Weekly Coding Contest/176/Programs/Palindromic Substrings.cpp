#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int countPalindromicSubstrings(string S, int k)
    {
        const int NO_OF_ALPHABETS = 26;
        vector <int> frequency(NO_OF_ALPHABETS);
        int odd_frequency_alphabets = 0;
        int answer = 0;
        for(int left = 0, right = 0; right < S.size(); )
        {
            while(right < S.size() && right - left + 1 <= k)
            {
                int right_alpha = S[right] - 'a';
                frequency[right_alpha]++;

                odd_frequency_alphabets += (frequency[right_alpha]%2 == 1 ? 1 : -1);
                right++;
            }

            if(odd_frequency_alphabets <= 1)
            {
                answer++;
            }

            int left_alpha = S[left] - 'a';
            frequency[left_alpha]--;

            odd_frequency_alphabets += (frequency[left_alpha]%2 == 1 ? 1 : -1);
            left++;
        }

        return answer;
    }
};
