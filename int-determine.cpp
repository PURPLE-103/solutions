#include <bits/stdc++.h>
using namespace std;

long long powe(long long a,long long b)
{
    long long ans=1;
    for(int i=1 ; i<=b ; ++i)
        ans*=a;
    return ans;
} 

int main()
{
    int a = INT_MAX;
    long long b=powe(2,31);
    bool c = a>b;
    cout << "RANGE in int?(1=true 0=false) : " << c;
    return 0;
}
//int 범위는 대략 2x10^9
// -2,147,483,648 <= int <= 2,147,483,647
// -2^31 <= int <= 2^31-1