#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> tree[MAX_N];
vector <int> visited(MAX_N), distance_to(MAX_N);

class Solution {
  public:
    
    void dfs(int v, int parent_v, int &furthest)
    {
        visited[v] = true;
        
        for(int child_v : tree[v])
        {
            if(child_v == parent_v)
            {
                continue;
            }
            
            distance_to[child_v] = distance_to[v] + 1; 
            dfs(child_v, v, furthest);
        }
        
        if(distance_to[v] > distance_to[furthest])
        {
            furthest = v;
        }
    }
    
    int get_diameter(int v)
    {
        int diameter_end_1 = v;
        distance_to[v] = 0;
        dfs(v, -1, diameter_end_1); 
        
        int diameter_end_2 = diameter_end_1;
        distance_to[diameter_end_1] = 0; 
        dfs(diameter_end_1, -1, diameter_end_2); 
        
        int diameter = distance_to[diameter_end_2];
        
        return diameter;
    }
    
    int maxCities(vector<int> &loc, vector<vector<int>> &roads, int k) 
    {
        int no_of_cities = loc.size(); 
        for(int i = 0; i < no_of_cities; i++)
        {
            tree[i].clear();
            visited[i] = false;
        }
        
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0] - 1, v = roads[i][1] - 1; 
            if(abs(loc[u] - loc[v]) <= k)
            {
                tree[u].push_back(v); 
                tree[v].push_back(u);
            }
        }
        
        int answer = 0;
        for(int i = 0; i < no_of_cities; i++)
        {
            if(!visited[i])
            {
                int diameter = get_diameter(i); 
                answer = max(answer, diameter + 1);
            }
        }
        
        return answer;
    }
};