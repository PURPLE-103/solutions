/* 
 * Author: PURPLE103
 * Time: 2025-04-14 00:29:31
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vl = std::vector<ll>;
using vii = std::vector<pair<int, int> >;
using vvl = std::vector<vl>;
using vll = std::vector<pair<ll , ll> >;
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
#define lob(a,x) lower_bound(all(a),x)
#define upb(a,x) upper_bound(all(a),x)

//const int p=998244353;
//ll po(ll a,ll b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {ll u=po(a,b/2);return (u*1LL*u)%p;} else {ll u=po(a,b-1);return (a*1LL*u)%p;}}

void solve()
{
    ll N;
    vector<bitset<32>> input;
    ll bitmax;
    vl a;
    ll max_val=-1;
    cin >> N;
    a.assign(N+2,0);
    for(ll i=0 ; i<N ; ++i)
    {
        ll itmp;
        ll cnt=0;
        cin >> itmp;
        bitset<32> bittmp(itmp);
        input.eb(itmp);
    }
    for(ll i=0 ; i<N ; ++i)
    {
        ll cnt=0;
        for(ll j=0 ; j<N ; ++j)
            cnt+=(input[i]^input[j]).to_ullong();
        if(cnt > max_val)
            max_val=cnt;
    }
    cout << max_val << "\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    cout.flush();
    return 0;
}