#include <bits/stdc++.h>
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
#define INF 0x3f3f3f3f
using namespace std;
// set<int>::iterator it;
// 用树状数组维护dp，求LIS
struct node
{
    int val;
    int num;
};
struct node a[maxn];
int n;
int c[maxn] = {0};
bool cmp(node a, node b)
{
    return a.val == b.val ? a.num < b.num : a.val < b.val;
}
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        c[i] = max(c[i], v);
    }
    return;
}
int query(int x)
{
    int res = -INF;
    for (int i = x; i; i -= lowbit(i))
    {
        res = max(c[i], res);
    }
    return res;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    f(i, 1, n)
    {
        cin >> a[i].val;
        a[i].num = i; // 离散化
    }
    sort(a + 1, a + n + 1, cmp); // 按权值优先排序,
    int ans = 0;
    f(i, 1, n)
    {
        //dp[i] = max(dp[j]+1) 1<=j<i
        int maxx = query(a[i].num);
        update(a[i].num, ++maxx);
        ans = max(ans, maxx);
    }

    cout << ans << endl;
    return 0;
}