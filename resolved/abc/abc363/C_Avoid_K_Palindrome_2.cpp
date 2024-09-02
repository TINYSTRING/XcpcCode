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
int n, k;
set<string> st;
// 检查是否是回文
bool check(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
// permute
void permute(string s, int l)
{
    sort(s.begin(), s.end());
    st.insert(s);
    while (next_permutation(s.begin(), s.end()))
    {
        st.insert(s);
    }
};

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    permute(s, 0);
    for (auto i : st)
    {
        f(j, 0, i.size() -k)
        {
            if (check(i.substr(j, k)))
            {
                ans++;
                break;
            }
        }
    }
    cout << st.size()-ans << endl;

    return 0;
}