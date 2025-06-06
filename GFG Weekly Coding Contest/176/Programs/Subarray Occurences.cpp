#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
vector <vector <int> > indices(MAX_N);

class Solution
{
  public:
    vector<int> countOccurrences(
        int no_of_elements,
        int no_of_queries,
        vector<int> &A,
        vector<vector<int>> &queries)
    {
        int last_label = 0;
        map <int, int> label;

        for(int i = 0; i < MAX_N; i++)
        {
            indices[i].clear();
        }


        for(int i = 0; i < A.size(); i++)
        {
            if(label.count(A[i]) == 0)
            {
                label[A[i]] = last_label++;
            }

            indices[label[A[i]]].push_back(i);
        }

        vector <int> answer(no_of_queries);
        for(int q = 0; q < no_of_queries; q++)
        {
            int left = queries[q][0], right = queries[q][1], k = queries[q][2];

            if(label.count(k) == 0)
            {
                answer[q] = 0;
                continue;
            }

            k = label[k];

            int L = lower_bound(indices[k].begin(), indices[k].end(), left) - indices[k].begin();
            int R = upper_bound(indices[k].begin(), indices[k].end(), right) - indices[k].begin();

            answer[q] = R - L;
        }

        return answer;
    }
};
