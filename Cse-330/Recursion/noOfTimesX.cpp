#include <bits/stdc++.h>
using namespace std;
void func(int x, int n)
{
    if (n == 0)
        return;
    cout << x << endl;
    func(x, n - 1);
}
int main()
{
    int x, n;
    cin >> x >> n;
    func(x, n);
    return 0;
}