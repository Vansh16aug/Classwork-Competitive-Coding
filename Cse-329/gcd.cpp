#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(a, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = gcd(a, b);
    return 0;
}