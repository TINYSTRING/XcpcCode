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

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    n -= 2; // 例如 101~363<==>0~26,是为了转换成0-based计数
    //1,2:0~8 3,4:10~99==0~89
    int a = 9;
    while (n >= 2 * a)
    {
        n -= 2 * a;
        a *= 10;
    }
    string s = to_string(n % a + a / 9); // n%a是为了得到在当前位数中的数，a/9是为了得到缺的0的个数
    string t = s;
    reverse(all(t));
    if (n < a) // 说明现在是奇位数
    {
        s.pop_back();
    }
    s += t;
    cout << s << endl;

    return 0;
}
