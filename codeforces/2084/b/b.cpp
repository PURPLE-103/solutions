/*
 * Author: PURPLE103
 * Time: 2025-04-05 23:42:58
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

ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

void solve()
{
    ll N,itmp,mi=po(10,18)+1;
    vl A;
    string stmp;
    cin >> N;
    cin.ignore();
    getline(cin, stmp);
    istringstream iss(stmp);
    while (iss >> itmp)
    {
        A.eb(itmp);
        if(itmp < mi)
            mi = itmp;
    }
    sort(all(A));
    ll cnt=0;
    for(ll i=N-1 ; i>=1 ; --i)
    {
        if(A[i]%A[0] == 0)
            cnt++;
        if(cnt >= 2)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return ;
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