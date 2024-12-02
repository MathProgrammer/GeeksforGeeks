class Solution {
  public:
    int findMax(int no_of_benches, int no_of_students, int bench_capacity) 
    {
        if(no_of_students <= no_of_benches)
        {
            return no_of_students;
        }
        
        if(bench_capacity*1LL*no_of_benches < no_of_students*1LL)
        {
            return -1;
        }
        
        int left = 0, right = no_of_benches;
        //Left <= Answer < Right
        while(right - left > 1)
        {
            int single_benches = (left + right)/2; 
            
            int full_benches = no_of_benches - single_benches ; 
            if(full_benches*1LL*bench_capacity + single_benches >= no_of_students)
            {
                left = single_benches ;
            }
            else 
            {
                right = single_benches;
            }
            
        }
        
        int max_single_benches = left;
        return max_single_benches;
    }
};