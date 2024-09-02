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
template <class T> pair<T, int> findmax(T a[], int n)
{
    map<T, int> cnt;
    f(i, 1, n)
    {
        cnt[a[i]]++;
    }
    pair<T, int> maxcnt;
    for (auto i : cnt)
    {
        if (i.second > maxcnt.second)
        {
            maxcnt.first = i.first;
            maxcnt.second = i.second;
        }
    }
    return maxcnt;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        char type;
        cin >> type;
        int n;
        cin >> n;
        if (type == 'I')
        {
            int* a = new int[n + 2];
            f(i, 1, n)
            {
                cin >> a[i];
            }
            auto ans = findmax(a, n);
            cout << ans.first << " " << ans.second << endl;
        }
        else if (type == 'C')
        {
            char* a = new char[n + 2];
            f(i, 1, n)
            {
                cin >> a[i];
            }
            auto ans = findmax(a, n);
            cout << ans.first << " " << ans.second << endl;
        }
        else if (type == 'S')
        {
            string* a = new string[n + 2];
            f(i, 1, n)
            {
                cin >> a[i];
            }
            auto ans = findmax(a, n);
            cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}