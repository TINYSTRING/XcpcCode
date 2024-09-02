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
        int h, n;
        cin >> h >> n;
        vector<int> a(n + 1);
        f(i, 1, n)
        {
            cin >> a[i];
        }
        vector<int> c(n + 1);
        f(i, 1, n)
        {
            cin >> c[i];
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        f(i, 1, n)
        {
            pq.push({1, a[i], i});
        }
        while (!pq.empty())
        {
            auto [d, x, i] = pq.top();
            pq.pop();
            h -= x;
            if (h <= 0)
            {
                cout << d << endl;
                break;
            }
            d += c[i];
            pq.push({d, a[i], i});
        }
    }

    return 0;
}