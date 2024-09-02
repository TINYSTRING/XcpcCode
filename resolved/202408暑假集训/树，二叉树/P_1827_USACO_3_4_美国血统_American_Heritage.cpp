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
    string pre, in;
    cin >> in >> pre;
    function<void(string, string)> solve = [&](string pre, string in) -> void {
        if (pre.size() == 0)
        {
            return;
        }
        char root = pre[0];
        int k = in.find(root);
        pre.erase(pre.begin());
        string prel = pre.substr(0, k), prer = pre.substr(k);
        string inl = in.substr(0, k), inr = in.substr(k + 1);
        solve(prel, inl); // 左子树
        solve(prer, inr); // 右子树
        cout << root;     // 根
    };
    solve(pre, in);

    return 0;
}