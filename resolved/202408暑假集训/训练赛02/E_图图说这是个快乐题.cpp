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

// 生成第K级地毯的函数
vector<string> gcarpet(int K)
{
    if (K == 0)
    {
        return vector<string>{"#"};
    }

    // 生成较小的第(K-1)级地毯
    vector<string> scarpet = gcarpet(K - 1);
    int size = scarpet.size();
    vector<string> ncarpet(size * 3);

    // 填充新的地毯
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == 1)
            { // 中间的行
                ncarpet[i * size + j] = scarpet[j] + string(size, '.') + scarpet[j];
            }
            else
            { // 顶部和底部的行
                ncarpet[i * size + j] = scarpet[j] + scarpet[j] + scarpet[j];
            }
        }
    }

    return ncarpet;
}

// 打印地毯的函数
void print_carpet(const vector<string>& carpet)
{
    for (const string& row : carpet)
    {
        cout << row << endl;
    }
}

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    // 生成第N级地毯
    vector<string> carpet = gcarpet(n);

    // 打印地毯
    print_carpet(carpet);

    return 0;
}