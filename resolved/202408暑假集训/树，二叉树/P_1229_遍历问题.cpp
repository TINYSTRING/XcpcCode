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
    string pre, suf;
    cin >> pre >> suf;
    int ans = 0;
    f(i, 0, pre.size() - 2)
    {
        string a = pre.substr(i, 2);
        f(j, 0, suf.size() - 2)
        {
            string b = suf.substr(j, 2);
            reverse(all(b));
            if (a == b)
            {
                ans++;
            }
        }
    }
    cout << (1 << ans) << endl;

    return 0;
}