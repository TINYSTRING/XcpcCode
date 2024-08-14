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
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = "*" + a;

    vector<char> tree(1 << (n + 2));
    function<void(int, int, int)> build = [&](int l, int r, int rt) {
        if (l == r)
        {
            tree[rt] = ((a[l] == '0') ? 'B' : 'I');
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        tree[rt] = (tree[rt << 1] == tree[rt << 1 | 1]) ? tree[rt << 1] : 'F';
    };
    build(1, 1 << n, 1);
    // 后序遍历
    function<void(int, int, int)> dfs = [&](int l, int r, int rt) {
        if (l == r)
        {
            cout << tree[rt];
            return;
        }
        int m = (l + r) >> 1;
        dfs(l, m, rt << 1);
        dfs(m + 1, r, rt << 1 | 1);
        cout << tree[rt]; // 输出根节点
    };
    dfs(1, 1 << n, 1);

    return 0;
}