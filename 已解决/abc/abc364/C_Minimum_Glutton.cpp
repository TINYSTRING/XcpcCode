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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    f(i, 0, n - 1)
    {
        cin >> a[i];
    }
    f(i, 0, n - 1)
    {
        cin >> b[i];
    }
    int ans = 0;
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    int cnt = 0;
    f(i, 0, n - 1)
    {
        if (cnt <= x)
        {
            cnt += a[i];
            ans++;
        }
        else
        {
            break;
        }
    }
    cnt = 0;
    int ans1 = 0;
    f(i, 0, n - 1)
    {
        if (cnt <= y)
        {
            cnt += b[i];
            ans1++;
        }
        else
        {
            break;
        }
    }
    cout << min(ans, ans1) << endl;
    return 0;
}