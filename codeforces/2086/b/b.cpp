/*
 * Author: PURPLE103
 * Time: 2025-04-05 11:10:24
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair

void solve()
{
    ll N, K, X, partsum = 0;
    vector<ll> input;
    cin >> N >> K >> X;
    for (int i = 1; i <= N; ++i)
    {
        int itmp;
        cin >> itmp;
        input.pb(itmp);
        partsum += itmp;
    }
    if (partsum * K < X)
        cout << "0\n";
    else
    {
        ll tmp, cnt;
        tmp = X % partsum;
        cnt = X / partsum * N;
        if(tmp == 0)
            cout << N*K-cnt+1 << "\n";
        else
        {
            for(int i = 1 ; i<=N ; ++i)
            {
                tmp-=input[N-i];
                if(tmp<=0)
                {
                    cout << N*K-(cnt+i-1) << "\n";
                    break;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}