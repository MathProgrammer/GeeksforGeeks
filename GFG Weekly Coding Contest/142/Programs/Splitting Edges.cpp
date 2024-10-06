class Solution
{
  public:

    void dfs(int v, int parent_v, vector <vector <int> > &tree, vector <int> &values,
        vector <int> &no_of_2s, vector <int> &no_of_3s, vector <int> &parent)
    {
        parent[v] = parent_v;
        
        switch(values[v])
        {
            case 2 : no_of_2s[v]++; 
                    break;
            case 3 : no_of_3s[v]++;
                    break;
        }
     
        for(int child_v : tree[v])
        {
            if(child_v != parent_v)
            {
                dfs(child_v, v, tree, values, no_of_2s, no_of_3s, parent);
                
                no_of_2s[v] += no_of_2s[child_v];
                no_of_3s[v] += no_of_3s[child_v];
            }
        }
    }
    
    int splittingEdges(int n, vector<int> &values, vector<vector<int>> &edges)
    {
        vector <vector <int> > tree(n); 
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v); 
            tree[v].push_back(u);
        }
        
        vector <int> no_of_2s(n), no_of_3s(n), parent(n);
        dfs(0, -1, tree, values, no_of_2s, no_of_3s, parent);
        
        int total_2s = no_of_2s[0], total_3s = no_of_3s[0];
        int removeable_edges = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1]; 
            if(v == parent[u])
            {
                swap(u, v);
            }
            
            int subtree_2s = no_of_2s[v], subtree_3s = no_of_3s[v]; 
            int remaining_2s = total_2s - subtree_2s, remaining_3s = total_3s - subtree_3s;
            
            if(min(subtree_2s, remaining_2s) > 0 && min(subtree_3s, remaining_3s) > 0)
            {
                removeable_edges++;
            }
        }
        
        return removeable_edges; 
    }
};
