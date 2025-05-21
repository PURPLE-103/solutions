/* 
 * Author: PURPLE103
 * Time: 2025-04-05 23:43:06
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

void swaploc(vll &inp,ll a,ll b)
{
    pair<ll,ll> temp;
    temp = inp[a];
    inp[a] = inp[b];
    inp[b] = temp;
}

void solve()
{
    ll N,itmp,cnt,same_cnt=0;
    vll inp;
    unordered_map<ll,ll> inp_map;
    string stmp;
    queue<pair<ll,ll>> ans,loc_list;
    cin >> N;
    inp.assign(N+1,mp(0,0));
    cin.ignore();
    getline(cin, stmp);
    istringstream iss(stmp);
    cnt=-1;
    while (iss >> itmp)
        inp[++cnt].F=itmp-1;
        
    iss.clear();
    stmp="";
    getline(cin, stmp);
    iss.str(stmp);
    cnt=-1;
    while (iss >> itmp)
    {
        inp[++cnt].S=itmp-1;
        if(inp[cnt].F == inp[cnt].S)
        {
            ++same_cnt;
            loc_list.push(mp(cnt,itmp-1));
        }
        inp_map[inp[cnt].F] = inp[cnt].S;
    }
    //judging if possible
    if(same_cnt%2 != N%2)
    {
        cout << "-1\n";
        return;
    }
    for(ll i=0 ; i<=N ; ++i)
    {
        if(inp_map[i] == i)
            continue;
        else if(inp_map[inp_map[i]] == i)
            continue;
        else
        {
            cout << "-1\n";
            return;
        }
    }
    ll cur_same=-1;
    ll temp_same_cur=N/2-same_cnt/2;
    while(!loc_list.empty())
    {
        pair<ll,ll> fr;
        fr = loc_list.front();
        loc_list.pop();
        if(inp_map[fr.S] == fr.S)
        {
            for(ll i=temp_same_cur ; i<=N/2+same_cnt/2-1 ; ++i)
            {
                if(inp[i].F != inp[i].S)
                {
                    temp_same_cur = i;
                    break;
                }
            }
            swaploc(inp,fr.F,temp_same_cur);
            temp_same_cur+=1;
        }
    }
    for(ll i=0 ; i<N/2-same_cnt/2 ; ++i)
    {
        for(ll i = )
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    cout.flush();
    return 0;
}