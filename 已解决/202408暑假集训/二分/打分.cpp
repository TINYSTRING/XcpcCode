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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    f(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int sum = 0;
    f(i, 2, n - 1)
    {
        sum += a[i];
    }
    if (sum + m > a[n] * (n - 2))
    {
        m -= a[n] * (n - 2) - sum;
        int x = m / (n - 1);
        int y = m % (n - 1);
        if (y > 0)
        {
            y--;
        }
        cout << a[n] * (n - 2) + x * (n - 2) + y << endl;
    }
    else
    {
        cout << sum + m << endl;
    }
    return 0;
}