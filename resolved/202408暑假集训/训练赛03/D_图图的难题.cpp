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

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> a(n), b(n);
        unordered_map<int, int> mpa, mpb; // 不能用map，会超时

        for (int i = 0; i < n; i++)
            cin >> a[i], mpa[a[i]]++;
        for (int i = 0; i < n; i++)
            cin >> b[i], mpb[b[i]]++;

        if (n <= 2)
        {
            cout << "Bob" << endl;
            continue;
        }

        int al = 0, ar = n - 1, bl = 0, br = n - 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (i == 0)
            { // A先要选下一步B拿不到的值
                if (a[0] != b[0] && a[0] != b[n - 1])
                {
                    mpa[a[0]]--;
                    al++;
                }
                else if (a[n - 1] != b[0] && a[n - 1] != b[n - 1])
                {
                    mpa[a[n - 1]]--;
                    ar--;
                }
                else
                { // 没有下一步B拿不到的值
                    mpa[a[0]]--;
                    al++;
                }
            }
            else
            {
                if (mpb[a[al]])
                {
                    mpa[a[al]]--;
                    al++;
                }
                else if (mpb[a[ar]])
                {
                    mpa[a[ar]]--;
                    ar--;
                }
                else
                {
                    mpa[a[al]]--;
                    al++;
                }
            }

            if (mpa[b[bl]] == 0)
            {
                mpb[b[bl]]--;
                bl++;
            }
            else if (mpa[b[br]] == 0)
            {
                mpb[b[br]]--;
                br--;
            }
            else
            {
                mpb[b[bl]]--;
                bl++;
            }
        }

        if (b[bl] == a[al])
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }

    return 0;
}