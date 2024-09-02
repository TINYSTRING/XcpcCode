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
class Group
{
  public:
    virtual int add(int x, int y) = 0; // 输出加法的运算结果
    virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};
class GroupA : public Group
{
  public:
    int add(int x, int y)
    {
        return x + y;
    }
    int sub(int x, int y)
    {
        return x - y;
    }
};
class GroupB : public Group
{
  public:
    int add(int x, int y)
    {
        return x + y;
    }
    int sub(int x, int y)
    {
        string a = to_string(x);
        string b = to_string(y);
        while (a.size() < b.size())
        {
            a = "0" + a;
        }
        while (b.size() < a.size())
        {
            b = "0" + b;
        }
        
        string ans = "";
        reverse(all(a));
        reverse(all(b));
        f(i, 0, a.size() - 1)
        {
            if (a[i] >= b[i])
            {
                ans += to_string(a[i] - b[i]);
            }
            else
            {
                ans += to_string(((a[i] - '0') * 10 + (a[i] - '0') - (b[i] - '0'))%10);
            }
        }
        reverse(all(ans));
        return stoll(ans);
    }
};
class GroupC : public Group
{
  public:
    int add(int x, int y)
    {
        string a = to_string(x);
        string b = to_string(y);
        string ans = "";
        reverse(all(a));
        reverse(all(b));
        f(i, 0, min(a.size(), b.size()) - 1)
        {
            ans += to_string((a[i] - '0' + b[i] - '0') % 10);
        }
        f(i, min(a.size(), b.size()), a.size() - 1)
        {
            ans += a[i];
        }
        reverse(all(ans));
        return stoll(ans);
    }
    int sub(int x, int y)
    {
        string a = to_string(x);
        string b = to_string(y);
        while (a.size() < b.size())
        {
            a = "0" + a;
        }
        while (b.size() < a.size())
        {
            b = "0" + b;
        }
        
        string ans = "";
        reverse(all(a));
        reverse(all(b));
        f(i, 0, a.size() - 1)
        {
            if (a[i] >= b[i])
            {
                ans += to_string(a[i] - b[i]);
            }
            else
            {
                ans += to_string(((a[i] - '0') * 10 + (a[i] - '0') - (b[i] - '0'))%10);
            }
        }
        reverse(all(ans));
        return stoll(ans);
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int opt;
        cin >> opt;
        int a, b;
        cin >> a;
        char c;
        cin >> c;
        cin >> b;
        Group* p;
        if (opt == 1)
        {
            p = new GroupA;
            if (c == '+')
            {
                cout << p->add(a, b) << endl;
            }
            else
            {
                cout << p->sub(a, b) << endl;
            }
        }
        else if (opt == 2)
        {
            p = new GroupB;
            if (c == '+')
            {
                cout << p->add(a, b) << endl;
            }
            else
            {
                cout << p->sub(a, b) << endl;
            }
        }
        else if (opt == 3)
        {
            p = new GroupC;
            if (c == '+')
            {
                cout << p->add(a, b) << endl;
            }
            else
            {
                cout << p->sub(a, b) << endl;
            }
        }
    }

    return 0;
}