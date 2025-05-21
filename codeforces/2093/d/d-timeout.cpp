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

ll npower2;

vector<string> splitString(const string &s, const string &delimiters)
{
    vector<string> tokens;
    size_t start = s.find_first_not_of(delimiters);
    while (start != string::npos)
    {
        size_t end = s.find_first_of(delimiters, start);
        tokens.push_back(s.substr(start, end - start));
        start = s.find_first_not_of(delimiters, end);
    }
    return tokens;
}

vll findnum(vector<vl> &table, vll tar)
{
    vll ans;
    ll cur=0;
    ans.assign(tar.size(),mp(0,0));
    for (ll i = 1; i <= npower2; ++i)
    {
        for (auto j = 1; j <= npower2; ++j)
        {
            if(table[i][j] == tar[cur].F)
            {
                ++cur;
                ans[cur]=mp(i,j);
                if(cur == tar.size())
                    return ans;
            }
        }
    }
}

void dfs(ll x, ll y, ll len, ll &cnt, vector<vl> &table)
{
    if (len == 1)
    {
        table[x][y] = ++cnt;

        table[x + 1][y + 1] = ++cnt;

        table[x + 1][y] = ++cnt;

        table[x][y + 1] = ++cnt;
    }
    else
    {
        ll tmp = po(2, len - 1);
        dfs(x, y, len - 1, cnt, table);
        dfs(x + tmp, y + tmp, len - 1, cnt, table);
        dfs(x + tmp, y, len - 1, cnt, table);
        dfs(x, y + tmp, len - 1, cnt, table);
    }
}

void solve()
{
    vector<vl> table;
    ll cnt = 0;
    ll N, Q;
    queue<pair<ll, ll>> ans;
    vll qlist;
    cin >> N >> Q;
    cin.ignore();
    npower2 = po(2, N);
    table.assign(npower2 + 1, vl(npower2 + 1, 0));
    for (ll i = 0; i < Q; ++i)
    {
        ll tmpcnt=0;
        string stmp;
        vs input;
        getline(cin, stmp);
        input = splitString(stmp, " ");
        if (input[0] == "->")
            ans.push(mp(stoll(input[1]), stoll(input[2])));
        else
        {
            ans.push(mp(-1, ++tmpcnt));
            qlist.eb(mp(stoll(input[1]),tmpcnt));
        }
    }
    dfs(1, 1, N, cnt, table);
    sort(all(qlist));
    vll anstoqlist=findnum(table,qlist);
    ll tmpcnt=0;
    while (!ans.empty())
    {
        auto fr = ans.front();
        ans.pop();
        if (fr.F == -1)
        {
            ++tmpcnt;
            for(ll i=0 ; i<qlist.size() ; ++i)
            {
                if(qlist[i].S == tmpcnt)
                {
                    cout << anstoqlist[i].F << " " << anstoqlist[i].S;
                    break;
                }
            }
        }
        else
            cout << table[fr.F][fr.S] << "\n";
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