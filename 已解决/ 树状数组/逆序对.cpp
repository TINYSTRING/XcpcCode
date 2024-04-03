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
int lowbit(int x)
{
    return x & -x;
}

void update(int i, int x)
{
    while (i <= n)
    {
        a[i] += x;
        i += lowbit(i);
    }
    return;
}

int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += a[i];
        i -= lowbit(i);
    }
    return ans;
}
void solve()
{
    cin >> n;
    int ans = 0;
    f(i, 1, n)
    {
        cin >> b[i];
        c[i] = b[i];
    }
    sort(b + 1, b + n + 1, greater<int>());
    f(i, 1, n)
    {
        mp[b[i]] = i; // 离散化,使得如果错位,大的肯定会先出现,因为对应的序号较小
    }
    f(i, 1, n)
    {
        ans += query(mp[c[i]] - 1);
        update(mp[c[i]], 1);
    }
    cout << ans << endl;
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