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

bool judge(pii a, pii b)
{
    if (a.first * b.first + a.second * b.second == 0)
    {
        return true;
    }
    return false;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    pii a[3];
    f(i, 0, 2)
    {
        cin >> a[i].first >> a[i].second;
    }
    f(i, 0, 2)
    {
        f(j, 0, 2)
        {
            f(k, 0, 2)
            {
                if (i == j || j == k || i == k)
                {
                    continue;
                }
                if (judge({a[j].first - a[i].first, a[j].second - a[i].second},
                          {a[k].first - a[i].first, a[k].second - a[i].second}))
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}