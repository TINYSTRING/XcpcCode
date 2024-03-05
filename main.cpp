#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define endl '\n'
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 100000007
#define maxn (ll)(5e5 + 5000)
#define INF 0x3f3f3f3f
using namespace std;
// set<int>::iterator it;
//写一个树状数组
int a[maxn] = {0};
int n;
int b[maxn] = {0};
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
    int sum = 0;
    while (i > 0)
    {
        sum += a[i];
        i -= lowbit(i);
    }
    return sum;
}

void init(int n)
{
    f(i, 1, n)
    {
        cin >> b[i];
    }
    f(i, 1, n)
    {
        update(i, b[i] - b[i - 1]);
    }
    return;
}

void solve(void)
{
    char tmp;
    cin >> tmp;
    if (tmp == '1')
    {
        int x, y, k;
        cin >> x >> y >> k;
        update(x, k);
        update(y + 1, -k);
    }
    else
    {
        int x;
        cin >> x;
        cout << query(x) << endl; //查询前缀和，
    }
    return;
}

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    int t;
    cin >> t;
    init(n);
    while (t--)
    {
        solve();
    }
    return 0;
}