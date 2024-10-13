#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool hasGeekSubsequence(string S)
    {
        string pattern = "geek";
        int pattern_matched = 0;
        for(int i = 0; i < S.size() && pattern_matched < pattern.size(); i++)
        {
            if(S[i] == pattern[pattern_matched])
            {
                pattern_matched++;
            }
        }

        return (pattern_matched == pattern.size());
    }
};