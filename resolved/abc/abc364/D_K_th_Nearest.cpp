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
    f(i, 1, m)
    {
        int b, k;
        cin >> b >> k;
        int l = -1e9, r = 1e9;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            int id1 = lower_bound(a.begin() + 1, a.end(), b - mid) - a.begin();
            int id2 = upper_bound(a.begin() + 1, a.end(), b + mid) - a.begin();
            if (id2 - id1 < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << r + 1 << endl;
    }

    return 0;
}