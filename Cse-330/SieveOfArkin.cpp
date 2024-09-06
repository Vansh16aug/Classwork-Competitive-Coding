#include <bits/stdc++.h>
using namespace std;
int main()
{
    int limit;
    cout << "Enter the number ";
    cin >> limit;
    vector<int> sieve(limit + 1, 0);
    if (limit > 2)
        sieve[2] = 1;
    if (limit > 3)
        sieve[3] = 1;
    for (int x = 1; x * x <= limit; x++)
    {
        for (int y = 1; y * y <= limit; y++)
        {
            // Condition 1
            int n = (4 * x * x) + (y * y);
            if (n <= limit && n % 12 == 1 || n % 12 == 5)
            {
                sieve[n] ^= 1;
            }
            // Condition 2
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
            {
                sieve[n] ^= 1;
            }
            // Condition 3
            n = (3 * x * x) - (y * y);
            if (n <= limit && x > y && n % 12 == 11)
            {
                sieve[n] ^= 1;
            }
        }
    }
    // Remove mutiples
    // If any number in our list is the square of any number, then remove it.
    for (int i = 5; i * i <= limit; i++)
    {
        if (sieve[i])
        {
            // 25->
            for (int j = i * i; j <= limit; j += i * i)
            {
                sieve[j] = 0;
            }
        }
    }
    // Printing
    for (int i = 0; i < sieve.size(); i++)
    {
       if(sieve[i]){
           cout << i << " ";
       }
    }
    return 0;
}