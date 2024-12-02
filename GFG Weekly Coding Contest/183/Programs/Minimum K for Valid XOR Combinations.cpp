#include <vector> 

using namespace std; 

class Node
{
    public:
    int count;
    vector <Node*> child;
    
    Node()
    {
        count = 0;
        child.resize(2, nullptr);
    }
};

class Trie 
{
    private : 
    Node *root;
    const int NO_OF_BITS = 20;
    
    int is_bit_set(int n, int bit)
    {
        return ( (n&(1 << bit)) != 0 );
    }
    
    int get_count(Node* current, int opposite)
    {
        return current->child[opposite] == nullptr ? 
            0 : 
            current->child[opposite]->count;
    }
    
    public :
    Trie()
    {
        root = new Node();
    }
    
    void insert(int n)
    {
        //cout << "Inserting " << n << "\n";
        Node *current = root;
        for(int bit = NO_OF_BITS; bit >= 0; bit--)
        {
            int next_bit = is_bit_set(n, bit);
            
            if(current->child[next_bit] == nullptr)
            {
                current->child[next_bit] = new Node();
            }
            
            current = current->child[next_bit];
            current->count++;
        }
    }
    
    int count_xor_pairs_smaller(int n, int max_xor)
    {
        Node* current = root;
        int pairs = 0; 
        for(int bit = NO_OF_BITS; bit >= 0; bit--)
        {
            if(is_bit_set(max_xor, bit))
            {
                int same_bit = is_bit_set(n, bit);
                pairs += get_count(current, same_bit);
            }
            
            //Traverse the trie towards equality
            int required_bit = is_bit_set(n^max_xor, bit);
            if(current->child[required_bit] == nullptr)
            {
                break;
            }
            current = current->child[required_bit];
            
            if(bit == 0)
            {
                pairs += current->count;
            }
        }
        
        return pairs;
    }
};

class Solution 
{
  public:
    int count_of_valid_subarrays(vector <int> &prefix_xor, int max_xor)
    {
        Trie trie;
        int total_valid_subarrays = 0; 
        for(int i = 0; i < prefix_xor.size(); i++)
        {
            total_valid_subarrays += trie.count_xor_pairs_smaller(prefix_xor[i], max_xor);
            trie.insert(prefix_xor[i]);
        }
       
         return total_valid_subarrays;
    }
    
    int minimizeKForXOR(int no_of_valid_subarrays, vector<int>&A) 
    {
        vector <int> prefix_xor; 
        prefix_xor.push_back(0); 
        for(int i = 0; i < A.size(); i++)
        {
            int new_prefix_xor = prefix_xor.back()^A[i];
            prefix_xor.push_back(new_prefix_xor);
        }
        
        if(count_of_valid_subarrays(prefix_xor, 0) >= no_of_valid_subarrays)
        {
            return 0;
        }
        
        int left = 0, right = 1e6; 
        //Left < K <= Right 
        while(right - left > 1)
        {
            int mid = left + (right - left)/2; 
            if(count_of_valid_subarrays(prefix_xor, mid) >= no_of_valid_subarrays)
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }
        
        return right;
    }
};