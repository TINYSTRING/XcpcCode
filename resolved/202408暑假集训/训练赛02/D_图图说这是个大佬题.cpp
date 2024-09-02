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
int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    n--;
    int ans[] = {0, 2, 4, 6, 8};
    if (n <= 5)
    {
        cout << ans[n] << endl;
        return 0;
    }
    int k = 1;
    int sum = 5;
    while (sum < n)
    {
        sum += 4 * qpow(5, k);
        k++;
    }

    string a = "";
    f(i, 1, k - 1)
    {
        int t = n % 5;
        n /= 5;
        a = to_string(ans[t]) + a;
    }
    a = to_string(ans[n % 5]) + a;
    a.erase(0, a.find_first_not_of('0'));
    cout << a << endl;

    return 0;
}