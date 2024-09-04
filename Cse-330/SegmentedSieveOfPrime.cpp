#include <bits/stdc++.h>
using namespace std;
void print(vector<bool> prime, int n, int sum = 0)
{
    for (int i = 0; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i + sum << " ";
        }
    }
}
void SegmentedSieve(int l, int r, vector<bool> prime)
{
    vector<bool> RangePrime(r - l + 1, true);
    for (int i = 0; i < prime.size(); i++)
    {
        int first;
        if (prime[i])
        {
            if (l % i != 0)
                first = l - l % i + i;
            else
                first = l;
            for (int j = first - l; j < RangePrime.size(); j += i)
            {
                RangePrime[j] = false;
            }
        }
    }
    print(RangePrime, r - l, l);
}
void FindPrimeTillRange(int l, int r)
{
    vector<bool> prime(sqrt(r) + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(r); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= sqrt(r); j += i)
            {
                prime[j] = false;
            }
        }
    }
    // print(prime, sqrt(r));
    SegmentedSieve(l, r, prime);
}

int main()
{
    int l, r;
    cin >> l >> r;
    FindPrimeTillRange(l, r);
    return 0;
}