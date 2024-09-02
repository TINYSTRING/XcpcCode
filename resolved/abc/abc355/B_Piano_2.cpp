#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define lcm(a,b) (a*b)/gcd(a,b)
#define all(a) a.begin(),a.end()
#define mem(a,x) memset(a,x,sizeof(a))
#define f(i,s,e) for(int i=s;i<=e;i++)
#define ff(i,s,e) for(int i=s;i>=e;i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define maxn (ll)(2e5+5000)
#define INF LONG_LONG_MAX
using namespace std;
//set<int>::iterator it;
map<int,int>mp;
signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m),c(n+m);
    int len=0;
    for(auto &i:a)
    {
        cin>>i;
        c[len++]=i;
        mp[i]=1;
    }
    for(auto &i:b)
    {
        cin>>i;
        c[len++]=i;
        mp[i]=2;
    }
    sort(all(c));
    f(i,0,n+m-2)
    {
        if(mp[c[i]]==mp[c[i+1]]&&mp[c[i]]==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}