#include <bits/stdc++.h>
using namespace std;
void freqChar(string n)
{
    unordered_map<char, int> mpp;
    for (int i = 0; i < n.size(); i++)
    {
        mpp[n[i]]++;
    }
    for (auto &it : mpp)
    {
        cout << it.first << " = " << it.second << endl;
    }
}
int main()
{
    string n = "vansh kumar"; // a=6 , b=5 , c=5
    freqChar(n);
    return 0;
}