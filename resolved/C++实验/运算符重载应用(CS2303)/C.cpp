#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int long long
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
class Clock
{
  private:
    int hour, minute, second;

  public:
    Clock(int h, int m, int s) : hour(h), minute(m), second(s)
    {
    }
    Clock(const Clock& a)
    {
        hour = a.hour;
        minute = a.minute;
        second = a.second;
    }
    friend Clock operator++(Clock& a);
    friend Clock operator--(Clock& a, int);
    void showTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};
Clock operator++(Clock& a)
{
    a.second++;
    if (a.second == 60)
    {
        a.second = 0;
        a.minute++;
        if (a.minute == 60)
        {
            a.minute = 0;
            a.hour++;
            if (a.hour == 12)
            {
                a.hour = 0;
            }
        }
    }
    return a;
}
Clock operator--(Clock& a, int)
{
    a.second--;
    if (a.second == -1)
    {
        a.second = 59;
        a.minute--;
        if (a.minute == -1)
        {
            a.minute = 59;
            a.hour--;
            if (a.hour == -1)
            {
                a.hour = 11;
            }
        }
    }
    return a;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    Clock a(x, y, z);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            a.showTime();
            continue;
        }
        int flag = 0;
        if (x < 0)
        {
            flag = -1;
        }
        else if (x > 0)
        {
            flag = 1;
        }
        x = abs(x);
        while (x--)
        {
            if (flag==1)
            {
                ++a;
            }
            else if (flag==-1)
            {
                a--;
            }
        }
        a.showTime();
    }

    return 0;
}