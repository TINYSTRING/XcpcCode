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
template <class T> 
int findkey(T a[], int n, T key)
{
    f(i, 1, n)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return 0;
};
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
            int key;
            f(i, 1, n)
            {
                cin >> a[i];
            }
            cin >> key;
            cout << findkey(a, n, key) << endl;
        }
        else if (type == 'D')
        {
            double* a = new double[n + 2];
            double key;
            f(i, 1, n)
            {
                cin >> a[i];
            }
            cin >> key;
            cout << findkey(a, n, key) << endl;
        }
        else if (type == 'C')
        {
            char* a = new char[n + 2];
            char key;
            f(i, 1, n)
            {
                cin >> a[i];
            }
            cin >> key;
            cout << findkey(a, n, key) << endl;
        }
        else if (type == 'S')
        {
            string* a = new string[n + 2];
            string key;
            f(i, 1, n)
            {
                cin >> a[i];
            }
            cin >> key;
            cout << findkey(a, n, key) << endl;
        }
    }

    return 0;
}