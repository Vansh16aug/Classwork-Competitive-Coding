#include<bits/stdc++.h>
using namespace std;

int FermetLittleThm(int a, int p){
    if (a % p == 0 || a == 1) return 1;
    int n = pow(a,(p-1));
    if(n % p == 1){
        return 2;
    }
    return 3;
}

int main()
{
    int a;
    cout<<"Enter the value of a :"<<endl;
    cin>>a;
    int p;
    cout<<"Enter the value of p :"<<endl;
    cin>>p;

    if(FermetLittleThm(a,p) == 2)
        cout<<p<<" is a prime number"<<endl;
    else if(FermetLittleThm(a,p) == 3)
        cout<<p<<" is not a prime number"<<endl;
    else
        cout<<"The number you entered "<<p<<" is a multiple of "<<a<<endl;
    return 0;
}