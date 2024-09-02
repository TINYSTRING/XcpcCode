#include <bits/stdc++.h>
#include <iostream>
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
int n, m, tree[maxn << 2], mark[maxn << 2];
void push_down(int p, int len)//len,地板除的巧妙应用
{
    if (mark[p]) // 如果标记为1，说明需要翻转，那么左右子树的值就是总长度减去原来的值(原来的值是总长度减去原来的值）
    {
        mark[p << 1] ^= 1;
        mark[p << 1 | 1] ^= 1;
        tree[p << 1] = (len - len / 2) - tree[p << 1];
        tree[p << 1 | 1] = (len / 2) - tree[p << 1 | 1];
        mark[p] = 0;
    }
    return;
}
void build(int l = 1, int r = n, int p = 1)
{
    if (l == r) // 叶子节点
    {
        tree[p] = 0;
        return;
    }
    else
    {
        int mid = (l + r) >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r, p << 1 | 1);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
}
void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n) // cl=check left, cr=check right
{
    if (cl > r || cr < l)
    {
        return;
    }
    else if (cl >= l && cr <= r)
    {
        tree[p] = (cr - cl + 1) - tree[p];
        if (cr > cl)
        {
            mark[p] ^= 1;
        }
    }
    else
    {
        int mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1); // 下传标记
        update(l, r, d, p << 1, cl, mid);
        update(l, r, d, p << 1 | 1, mid + 1, cr);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
    return;
}
int query(int l, int r, int p = 1, int cl = 1, int cr = n)
{
    if (cl > r || cr < l)
    {
        return 0;
    }
    else if (cl >= l && cr <= r)
    {
        return tree[p];
    }
    else
    {
        int mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1); // 下传标记
        return query(l, r, p << 1, cl, mid) + query(l, r, p << 1 | 1, mid + 1, cr);
    }
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    build();
    f(i, 1, m)
    {
        int opt;
        cin >> opt;
        if (opt == 0)
        {
            int l, r;
            cin >> l >> r;
            update(l, r, 1); // 区间[l,r]每个数加d
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl; // 查询区间[l,r]的和
        }
    }

    return 0;
}