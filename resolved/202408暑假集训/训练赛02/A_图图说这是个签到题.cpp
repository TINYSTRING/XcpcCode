#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#define endl '\n'
#define ll long long
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
#define maxn (ll)(100)
#define INF LONG_LONG_MAX
using namespace std;

int vis[maxn][maxn], book[maxn], topo[maxn], in[maxn], n;

void dfs(int t)
{
    if (t == n)
    {
        f(i, 0, n - 1)
        {
            cout << char(topo[i] + 'a' - 1);
        }
        cout << endl;
        return;
    }
    f(i, 1, 26)
    {
        if (!in[i] && book[i])
        {
            topo[t] = i;
            book[i] = 0;
            f(j, 1, 26)
            {
                if (vis[i][j])
                {
                    in[j]--;
                }
            }
            dfs(t + 1);
            book[i] = 1;
            f(j, 1, 26)
            {
                if (vis[i][j])
                {
                    in[j]++;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, str2;
    while (getline(cin, str) && getline(cin, str2))
    {
        // 初始化
        mem(vis, 0);
        mem(book, 0);
        mem(topo, 0);
        mem(in, 0);
        n = 0;

        stringstream ss(str);
        char c;
        while (ss >> c)
        {
            if (c != ' ')
            {
                n++;
                book[c - 'a' + 1] = 1;
            }
        }
        for (int i = 0; i < str2.size(); i = i + 2)
        {
            char ch1 = str2[i];
            i += 2;
            char ch2 = str2[i];
            vis[ch1 - 'a' + 1][ch2 - 'a' + 1] = 1;
            in[ch2 - 'a' + 1]++;
        }
        dfs(0);
        cout << endl;
    }

    return 0;
}