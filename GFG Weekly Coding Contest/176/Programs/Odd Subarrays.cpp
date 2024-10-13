#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long choose_2(long long n)
    {
        return (n*(n - 1))/2;
    }

    long long countoddSubarrays(int n, vector<int> &A)
    {
        vector <vector <int>> no_of_subarrays(2, vector <int> (2, 0));
        long long answer = 0;

        no_of_subarrays[0][0] = 1;

        int parity_of_odd_elements = 0;
        for(int i = 0; i < A.size(); i++)
        {
            parity_of_odd_elements += (A[i]%2 == 1);
            parity_of_odd_elements %= 2;

            int length_parity = (i + 1)%2;
            no_of_subarrays[length_parity][parity_of_odd_elements]++;

            int same_parity_length = length_parity;
            int opposite_parity_content = 1 - parity_of_odd_elements;

            answer += no_of_subarrays[same_parity_length][opposite_parity_content];
        }

        return answer;
    }
};
