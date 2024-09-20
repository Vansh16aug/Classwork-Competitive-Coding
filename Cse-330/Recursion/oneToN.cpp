#include <bits/stdc++.h>
using namespace std;
void print(int i, int n)
{
    if (n > 0)
    {
        cout << i << endl;
    }
    print(i + 1, n - 1);
}
int main()
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}