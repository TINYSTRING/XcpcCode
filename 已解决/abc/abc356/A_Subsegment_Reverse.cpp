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

signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,l,r;
    cin>>n>>l>>r;
    l--,r--;
    vector<int> a(n);
    iota(all(a),1);
    reverse(a.begin()+l,a.begin()+r+1);
    for(auto x:a)
    {
        cout<<x<<" ";
    }


    return 0;
}