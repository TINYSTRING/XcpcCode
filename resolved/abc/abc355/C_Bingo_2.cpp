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
int prei[maxn], prej[maxn];
int d1, d2;
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    f(i, 1, t)
    {
        int a;
        cin >> a;
        int x = (a - 1) / n + 1; // 使j-1在（0，n-1）之间
        int y = (a - 1) % n + 1;
        prei[x]++;
        prej[y]++;
        if (prei[x] >= n || prej[y] >= n)
        {
            cout << i << endl;
            return 0;
        }
        if (x == y)//两个检查是独立的，所以不能用else if
        {
            d1++;
            if (d1 >= n)
            {
                cout << i << endl;
                return 0;
            }
        }
        if (x + y == n + 1)
        {
            d2++;
            if (d2 >= n)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}