#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
vector<bool> sieve(N + 1, true);
void createSieve()
{
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j+=i)
            {
                sieve[j] = false;
            }
        }
    }
}
vector<int> generatePrimes(int n)
{
    vector<int> ds;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            ds.push_back(i);
        }
    }
    return ds;
}
int main()
{
    createSieve();
    int l, r;
    cin >> l >> r;
    // step1: generate all primes till sqrt(r)
    vector<int> primes = generatePrimes(sqrt(r));

    // step2: dummy array to mark non-primes
    vector<int> dummy(r - l + 1, 1);
    // mark the multiples
    for (auto pr : primes)
    {
        int firstMultiple = (l / pr) * pr;
        if (firstMultiple < l)
            firstMultiple += pr;
        for (int j = max(pr * pr, firstMultiple); j <= r; j += pr)
        {
            dummy[j - l] = 0; // Mark non-prime
        }
    }
    // print all the primes in range
    for (int i = 0; i <= r - l; i++)
    {
        if (dummy[i] == 1)
        {
            cout << i + l << " ";
        }
    }
    return 0;
}