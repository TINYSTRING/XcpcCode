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
int ans;

void dfs(vector<int> in, vector<int> suf)
{
    if (in.size() == 1||suf.size()==1)
    {
        ans = min(ans, in[0]); // 叶子节点
        return;
    }
    if (in.size() == 0 || suf.size() == 0)
    {
        return;
    }
    int root = suf.back();                      // 后序遍历的最后一个节点是根节点
    int pos = find(all(in), root) - in.begin(); // 找到根节点在中序遍历中的位置
    vector<int> in1(in.begin(), in.begin() + pos);
    vector<int> in2(in.begin() + pos + 1, in.end());
    // 要把当前的根节点去掉
    vector<int> suf1(suf.begin(), suf.begin() + in1.size());
    vector<int> suf2(suf.begin() + in1.size(), suf.end() - 1);
    ans = min(ans, root);
    dfs(in1, suf1); // 左子树
    dfs(in2, suf2); // 右子树
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string suf1, in1;
    while (getline(cin, in1) )
    {
        getline(cin, suf1);
        vector<int> suf, in;
        stringstream ss1(in1), ss2(suf1); // 字符串流
        int x;
        while (ss1 >> x)
        {
            in.pb(x);
        }
        while (ss2 >> x)
        {
            suf.pb(x);
        }
        // 找最小的叶子节点
        ans = 4e18;
        dfs(in, suf);
        cout << ans << endl;
    }

    return 0;
}