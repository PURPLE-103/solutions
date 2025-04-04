#include <bits/stdc++.h>
using namespace std;
 
void ps()
{
    int t;
 
    cin >> t;
    for(int i =1 ; i<=t ; ++i)
    {
        int n,itmp;
        long long sum1=0,sum2=0;
        vector<long long> b;
        vector<long long> groupa,groupb;
        string stmp;
        cin >> n;
        cin.ignore();
        getline(cin,stmp);
        istringstream iss(stmp);
        while(iss >> itmp)
            b.push_back(itmp);
        sort(b.begin(),b.end());
        for(int j = 1 ; j<=n-1 ; ++j)
        {
            sum1+=b[j];
            groupa.push_back(b[j]);
            sum2+=b[n-1+j];
            groupb.push_back(b[n-1+j]);
        }
        groupb.push_back(b[0]);
        groupb.push_back(b[2*n-1]);
        groupa.push_back((sum2-sum1)+b[0]+b[2*n-1]);
        for(int j = 0 ; j<n ; ++j)
            cout << groupb[j] << " " << groupa[j] << " ";
        cout << groupb[n] << "\n";
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ps();
    cout.flush();
    return 0;
}