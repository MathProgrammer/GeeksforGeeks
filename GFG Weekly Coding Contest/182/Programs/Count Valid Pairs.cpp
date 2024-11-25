#include <vector> 

using namespace std; 

class DSU
{
    int no_of_vertices; 
    vector <int> parent; 
    
    public :
    DSU(int n)
    {
        no_of_vertices = n; 
        
        parent.resize(no_of_vertices + 1); 
        for(int v = 0; v < no_of_vertices; v++)
        {
            parent[v] = v;
        }
    }
    
    int get_parent(int v)
    {
        while(parent[v] != v)
        {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        
        return parent[v];
    }
    
    void combine(int u, int v)
    {
        u = get_parent(u); 
        v = get_parent(v);
        
        if(u == v)
        {
            return;
        }
        
        parent[u] = v;
    }
};

class Solution {
  public:
 
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    long long choose_2(long long n)
    {
        return (n*(n - 1))/2;
    }
    
    long long cntValid(vector<int> &w) 
    {
        const int NO_OF_BITS = 31; 
        DSU dsu(NO_OF_BITS);
        for(int i = 0; i < w.size(); i++)
        {
            for(int bit1 = 0; bit1 < NO_OF_BITS; bit1++)
            {
                for(int bit2 = bit1 + 1; bit2 < NO_OF_BITS; bit2++)
                {
                    if(is_bit_set(w[i], bit1) && is_bit_set(w[i], bit2))
                    {
                        dsu.combine(bit1, bit2);
                    }
                }
            }
        }
        
        vector <long long> component_size(NO_OF_BITS);
        for(int i = 0; i < w.size(); i++)
        {
            for(int bit = 0; bit < NO_OF_BITS; bit++)
            {
                if(is_bit_set(w[i], bit))
                {
                    int parent = dsu.get_parent(bit);
                    component_size[parent]++;
                    break;
                }
            }
        }
        
        long long valid_pairs = 0; 
        for(int bit = 0; bit < NO_OF_BITS; bit++)
        {
            valid_pairs += choose_2(component_size[bit]);
        }
        
        return valid_pairs;
    }
};