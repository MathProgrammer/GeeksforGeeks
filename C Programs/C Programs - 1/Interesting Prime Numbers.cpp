#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &no_of_interesting_primes_till)
{
    vector <int> is_prime(1e5 + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= 1e5; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple <= 1e5; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }

    vector <int> is_interesting(1e5 + 1, false);
    for(long long a = 1; a*a <= 1e5; a++)
    {
        for(long long b = 1; a*a + b*b*b*b <= 1e5; b++)
        {
            is_interesting[a*a + b*b*b*b] = true;
        }
    }

    for(int i = 1; i <= 1e5; i++)
        no_of_interesting_primes_till[i] = no_of_interesting_primes_till[i - 1] +
                                        (is_prime[i] && is_interesting[i]);
}

int main()
{
	vector <int> no_of_interesting_primes_till(1e5 + 1);
	precompute(no_of_interesting_primes_till);

	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
	{
	    int number;
	    scanf("%d", &number);
	    printf("%d\n", no_of_interesting_primes_till[number]);
	}

	return 0;
}
