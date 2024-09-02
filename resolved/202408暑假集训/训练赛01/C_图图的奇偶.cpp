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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        map<int, vector<int>> mp;
        f(i, 0, n - 1)
        {
            cin >> a[i];
            mp[a[i]].pb(i + 1);
        }
        unique(a.begin(), a.end());
        sort(all(a), greater<int>());
        f(i, 0, a.size() - 1)
        {
            for (auto x : mp[a[i]])
            {
                if (x % 2 == 1)
                {
                    cout << a[i] << endl;
                    goto out;
                }
            }
        }
    out:;
    }

    return 0;
}