/* 
 * Author: PURPLE103
 * Time: 2025-04-14 01:37:38
 */
#include <bits/stdc++.h>
using namespace std;

//const int p=998244353;
//int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%p;} else {int u=po(a,b-1);return (a*1LL*u)%p;}}
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

ll cal_rizz(const vl b,const bool stat)
{
    ll ans=0;
    for(ll i=0 ; i<b.size() ; ++i)
    {
        if(stat == true)
            ans+=b[i]*(i+1);
        else
            ans+=b[i]*(b.size()-i);
    }
    return ans;
}

void solve()
{
    ll Q;
    vl ans;
    ll prev_rizz;
    bool stat=true;
    cin >> Q;
    for(ll i = 1 ; i<=Q ; ++i)
    {
        ll itmp,itmp2;
        cin >> itmp;
        if(itmp == 3)
        {
            cin >> itmp2;
            if(stat == true)
                ans.eb(itmp2);
            else
                ans.insert(ans.begin(),itmp2);
        }
        else if(itmp == 2){
            stat = !stat;}
        else if(itmp == 1)
        {
            if(stat == true)
            {
                ans.insert(ans.begin(),ans.back());
                ans.erase(ans.end()-1);
            }
            else
            {
                ans.insert(ans.end(),ans.front());
                ans.erase(ans.begin());
            }
        }
        cout << cal_rizz(ans,stat) << "\n";
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