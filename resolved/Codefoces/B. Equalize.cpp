#include <algorithm>
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define lcm(a, b) (a * b) / gcd(a, b)
#define all(a) a.begin(), a.end()
#define mem(a, x) memset(a, x, sizeof(a))
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 100000007
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;
void solve()
{
    set<int> s;
    int n;
    cin >> n;
    f(i, 1, n)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v;
    for (auto x : s)
    {
        v.pb(x);
    }
    int ans = 1, sum = 1;//至少能有一个区间长度
    int id = 0;
    f(i, 1, v.size() - 1)
    {
        if (v[i] - v[id] >= n)//考虑极差
        {
            ans = max(ans, sum);
            while (id < i && v[i] - v[id] >= n)
            {
                id++;
            }
            sum = i - id + 1;
        }
        else
        {
            sum++;
        }
    }
    ans = max(ans, sum);
    cout << ans << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}