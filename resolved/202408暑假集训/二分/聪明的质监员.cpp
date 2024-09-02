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
#define mod 1000000007
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<pii> a(n + 1);
    f(i, 1, n)
    {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> l(m + 1), r(m + 1);
    f(i, 1, m)
    {
        cin >> l[i] >> r[i];
    }
    auto count = [&](int x) -> int {
        int res = 0;
        vector<int> p(n + 1, 0);
        vector<int> pre(n + 1, 0);
        f(i, 1, n)
        {
            p[i] = p[i - 1] + (a[i].first >= x);
            pre[i] = pre[i - 1] + (a[i].first >= x) * a[i].second;
        }
        f(i, 1, m)
        {
            res += (pre[r[i]] - pre[l[i] - 1]) * (p[r[i]] - p[l[i] - 1]);
        }
        return res;
    };
    int l1 = 1, r1 = 1e7;
    int ans = INF;
    int tres = INF;
    while (l1 <= r1)
    {
        int mid = l1 + ((r1 - l1) >> 1);
        int res = count(mid);
        if(abs(res-s)<=tres)
        {
            tres = abs(res-s);
        }
        if (res > s)
        {
            l1 = mid + 1;
        }
        else if (res < s)
        {
            r1 = mid - 1;
        }else
        {
            tres = 0;
            break;
        }
    }
    cout << tres << endl;
    return 0;
}