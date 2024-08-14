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
    vector<pii> a(1 << n + 1);
    f(i, 1, (1 << n))
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    // 从叶子节点开始递归创建二叉树
    vector<pii> tree(1 << (n + 2)); // 二叉树的节点数为2^(n+1)-1
    function<void(int, int, int)> dfs = [&](int l, int r, int id) -> void {
        if (l == r)
        {
            tree[id] = a[l]; // 叶子节点的值
            return;
        }
        int mid = l + ((r - l) >> 1);
        dfs(l, mid, id << 1);         // 递归创建左右子树
        dfs(mid + 1, r, id << 1 | 1); // 递归创建左右子树
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    };
    dfs(1, 1 << n, 1); // 从根节点开始递归创建二叉树
    cout << min(tree[2], tree[3]).second << endl;
    return 0;
}