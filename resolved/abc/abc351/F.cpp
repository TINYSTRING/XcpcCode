#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define endl '\n'
#define all(a) a.begin(), a.end()
#define mem(a, x) memset(a, x, sizeof(a))
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 100000007
#define maxn (ll)(5e5 + 5000)
#define INF 0x3f3f3f3f
using namespace std;
// set<int>::iterator it;
int n;
map<int, int> mp;
int a[maxn] = {0};
int b[maxn] = {0};
int c[maxn] = {0};
int d[maxn] = {0};
int lowbit(int x)
{
    return x & -x;
}

void update(int i, int x, int y)
{
    while (i <= n)
    {
        a[i] += x;
        d[i] += y;
        i += lowbit(i);
    }
    return;
}

pii query(int i)
{
    int ans = 0;
    int ans1 = 0;
    while (i > 0)
    {
        ans += a[i];
        ans1 += d[i];
        i -= lowbit(i);
    }
    return {ans, ans1};
}
void solve()
{
    cin >> n;
    int ans = 0;
    ff(i, n, 1)
    {
        cin >> b[i];
        c[i] = b[i];
    }
    sort(b + 1, b + n + 1, greater<int>());
    int m=unique(b+1,b+n+1)-b-1;
    f(i, 1, m)
    {
        mp[b[i]] = i; // 离散化,使得如果错位,大的肯定会先出现,因为对应的序号较小,相当于第几大的数
    }
    f(i, 1, n)
    {
        auto [x, y] = query(mp[c[i]] - 1);
        ans += c[i] * x - y;
        update(mp[c[i]], 1, c[i]);
    }
    cout << abs(ans) << endl;
    mp.clear();
    return;
}

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}