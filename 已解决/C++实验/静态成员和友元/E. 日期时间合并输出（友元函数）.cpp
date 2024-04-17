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
class Time;
class Date
{
  private:
    int year, month, day;

  public:
    Date(){};
    Date(int d, int m, int y) : day(d), month(m), year(y){};
    friend void display(const Date& d, const Time& t);
};
class Time
{
  private:
    int hour, minute, second;

  public:
    Time(){};
    Time(int h, int m, int s) : hour(h), minute(m), second(s){};
    friend void display(const Date& d, const Time& t);
};
string check(int x)
{
    if (x < 10)
    {
        return "0" + to_string(x);
    }
    return "" + to_string(x);
}
void display(const Date& d, const Time& t)
{
    cout << d.year << "-" << check(d.month) << "-" << check(d.day);
    cout << " ";
    cout << check(t.hour) << ":" << check(t.minute) << ":" << check(t.second) << endl;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int d, m, y, h, mi, s;
        cin >> y >> m >> d >> h >> mi >> s;
        Date date(d, m, y);
        Time time(h, mi, s);
        display(date, time);
    }
    return 0;
}