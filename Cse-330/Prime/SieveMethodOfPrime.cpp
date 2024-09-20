#include <bits/stdc++.h>
using namespace std;
void Sieve(long long n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2; i*i <= n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (long long i = 0; i < n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}
int main()
{
    long long n = 23;
    Sieve(n);
    return 0;
}