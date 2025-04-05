/*
 * Author: PURPLE103
 * Time: 2025-04-05 11:10:24
 * after editorial
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lob(a,x) lower_bound(all(a),x)
#define upb(a,x) upper_bound(all(a),x)

void solve()
{
    ll N,K,X,sumofinput=0;
    vector<ll> input;
    cin >> N >> K >> X;
    for(ll i = 1 ; i<=N ; ++i)
    {
        ll itmp;
        cin >> itmp;
        input.eb(itmp);
        sumofinput+=itmp;
    }
    if(sumofinput*K < X)
    {
        cout << "0\n";
        return;
    }
    ll l,r,m;
    l = 1;
    r = N*K;
    while(l<=r)
    {
        m=l+(r-l)/2;
        ll cnt_input = (N*K-m+1)/N;
        ll cnt_leftlen = (N*K-m+1)%N;
        ll partsum = sumofinput*cnt_input;
        for(ll i=N ; i>=N-cnt_leftlen+1 ; --i)
            partsum+=input[i-1];
        if(partsum < X)
            r=m-1;
        else
            l=m+1;
    }
    cout << r << "\n";
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
    cout.flush();
    return 0;
}