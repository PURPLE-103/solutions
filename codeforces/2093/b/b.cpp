/*
 * Author: PURPLE103
 * Time: 2025-04-08 23:34:15
 */
#include <bits/stdc++.h>
using namespace std;

// const int p=998244353;
// int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%p;} else {int u=po(a,b-1);return (a*1LL*u)%p;}}
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
    ll X, K;
    cin >> X >> K;
    if ((X == 1 && K == 1) || (X != 1 && K != 1))
    {
        cout << "No\n";
        return;
    }
    if (X == 1)
    {
        ll p = 0;
        bool flag = true;
        for (ll i = 1; i <= K; ++i)
        {
            p *= 10;
            p += 1;
            for (ll j = 2; j <= sqrt(p); ++j)
            {
                if (p % j == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    else if (K == 1)
    {
        for (ll i = 2; i <= sqrt(X); ++i)
        {
            if (X % i == 0)
            {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
    cout.flush();
    return 0;
}