/*
 * Author: PURPLE103
 * Time: 2025-04-19 23:30:53
 */
#include <bits/stdc++.h>
using namespace std;

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

// const ll p=998244353;
// ll po(ll a,ll b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%p;} else {int u=po(a,b-1);return (a*1LL*u)%p;}}

template <class T>
inline void hash_combine(size_t &seed, T const &v)
{
    seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        size_t seed = 0;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);
        return seed;
    }
};

void operationD(unordered_set<pair<ll, ll>, pair_hash> &a, pair<ll, ll> pt)
{
    vl dx = {0, 0, 1, 1};
    vl dy = {0, 1, -1, 0};
    for (ll i = 0; i < dx.size(); ++i)
    {
        if (a.contains(mp(pt.F + dy[i], pt.S + dx[i])))
            a.erase(mp(pt.F + dy[i], pt.S + dx[i]));
        else
            a.insert(mp(pt.F + dy[i], pt.S + dx[i]));
    }
}

ll cntlev(unordered_set<pair<ll, ll>, pair_hash> &a, pair<ll, ll> pt)
{
    ll cnt = 0;
    vl dx = {0, 0, 1, 1};
    vl dy = {0, 1, -1, 0};
    for (ll i = 0; i < dx.size(); ++i)
    {
        if (a.contains(mp(pt.F + dy[i], pt.S + dx[i])))
            ++cnt;
    }
    return cnt;
}

void solve()
{
    ll N;
    vll input;
    vl dx = {0, -1, 1, 0, 0,1,-1};
    vl dy = {0, 0, 0, 1, -1,-2,2};
    unordered_set<pair<ll, ll>, pair_hash> a;
    cin >> N;
    for (ll i = 0; i < N; ++i)
    {
        pair<ll, ll> itmp;
        cin >> itmp.S >> itmp.F;
        input.eb(itmp);
        a.insert(itmp);
    }
    while (a.size() > 1)
    {
        pair<ll, ll> ptmp;
        ll maxtmp = 0;
        unordered_set<pair<ll, ll>, pair_hash> vis;
        for (auto i : a)
        {
            for (ll j = 0; j < dx.size(); ++j)
            {
                if(vis.contains(mp(i.F + dy[j], i.S + dx[j])))
                    continue;
                ll cnttmp = cntlev(a, mp(i.F + dy[j], i.S + dx[j]));
                if (cnttmp > maxtmp)
                {
                    maxtmp = cnttmp;
                    ptmp = mp(i.F + dy[j], i.S + dx[j]);
                }
                vis.insert(mp(i.F + dy[j], i.S + dx[j]));
            }
        }
        operationD(a, ptmp);
    }
    cout << a.begin()->S << " " << a.begin()->F << "\n";
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