/* 
 * Author: PURPLE103
 * Time: 2025-04-25 00:42:09
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

//const ll p=998244353;
//ll po(ll a,ll b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%p;} else {int u=po(a,b-1);return (a*1LL*u)%p;}}
//copy_n(istream_iterator<ll>(cin),N,back_inserter(input));

void solve()
{
    ll N,Q;
    vll input;
    vl inputrank;
    cin >> N,Q;
    for(ll i=0 ; i<N; ++i)
    {
        pair<ll,ll> plltmp;
        cin >> plltmp.F;
        plltmp.S = i;
        input.eb(plltmp);
    }
    inputrank.assign(N,0);
    sort(all(input));
    for(ll i=0 ; i<N ; ++i)
        inputrank[input[i].S]=i;
    while(Q--)
    {
        
    }
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