/*
 * Author: PURPLE103
 * Time: 2025-04-09 00:35:52
 */
#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
int po(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        int u = po(a, b / 2);
        return (u * 1LL * u) % p;
    }
    else
    {
        int u = po(a, b - 1);
        return (a * 1LL * u) % p;
    }
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vl = std::vector<ll>;
using vii = std::vector<pair<int, int>>;
using vvl = std::vector<vl>;
using vll = std::vector<pair<ll, ll>>;
using vd = std::vector<double>;
using vvd = std::vector<vd>;
using vs = std::vector<std::string>;
using vvs = std::vector<vs>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vc = std::vector<char>;
using vvc = std::vector<vc>;
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lob(a, x) lower_bound(all(a), x)
#define upb(a, x) upper_bound(all(a), x)

void solve()
{
    ll N,Q;
    cin >> N >> Q;
    while(Q>0)
    {
        string stmp;
        Q--;
        cin >> stmp;
        if(stmp == "->")
        {
            ll ans=0,dx,dy;
            cin >> dx >> dy;
            dx-=1; dy-=1;
            for(ll i=N-1 ; i>=0 ; --i)
            {
                ll v;
                ll xtmp=(dx>>i)&1;
                ll ytmp=(dy>>i)&1;
                if(xtmp == 0 && ytmp == 0) v=0;
                else if(xtmp == 1 && ytmp == 1) v=1;
                else if(xtmp == 1 && ytmp == 0) v=2;
                else if(xtmp == 0 && ytmp == 1) v=3;
                ans+=v<<(2*i);
            }
            cout << ans+1 << "\n";
        }
        else if(stmp == "<-")
        {
            ll dx=0,dy=0;
            ll D;
            cin >> D;
            --D;
            for(ll i=N-1 ; i>=0 ; --i)
            {
                ll xtmp=0,ytmp=0;
                ll ltmp=(D>>(2*i))&3;
                if(ltmp == 1){xtmp = 1<<i; ytmp=1<<i;}
                else if(ltmp == 2)xtmp = 1<<i;
                else if(ltmp == 3)ytmp=1<<i;
                dx+=xtmp;
                dy+=ytmp;
            }
            cout << dx+1 << " " << dy+1 << "\n";
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
    cout.flush();
    return 0;
}