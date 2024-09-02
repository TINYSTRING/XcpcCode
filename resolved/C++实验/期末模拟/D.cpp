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
string test(int s)
{
    if (s == 1)
    {
        return "旋转吹风--风力";
    }
    else
    {
        return "定向吹风--风力";
    }
}
// 家电
class appliance
{
  protected:
    string name;
    int power; // 功率
  public:
    appliance(string n, int p) : name(n), power(p)
    {
    }
    virtual void display() {

    };
};
// 电风扇
class fan : virtual public appliance
{
  protected:
    int fang;  // 风向
    int speed; // 风速
  public:
    fan(string n, int p, int s,int f) : appliance(n, p), speed(s),fang(f)
    {
    }
    void control(int s)
    {
        speed = s;
    }
    void control2(int s)
    {
        fang = s;
    }
    void display()
    {
    }
};
// 加湿器
class humi : virtual public appliance
{
  protected:
    float w1; // 实际水容量
    float w2; // 最大水容量
  public:
    humi(string n, int p, float w1, float w2) : appliance(n, p), w1(w1), w2(w2)
    {
    }
    void display()
    {
    }
    int alarm()
    {
        // 实际水容量不小于最大水容量的50%，则返回1；小于50%且不小于10%则返回2，小于10%则返回3
        if (w1 >= 0.5 * w2)
        {
            return 1;
        }
        else if (w1 >= 0.1 * w2)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
};
// 加湿风扇
class humi_fan : public fan, public humi
{
  protected:
    int dw; // 档位
  public:
    humi_fan(string n, int p, int s, int f,float w1, float w2,int d) : appliance(n, p), fan(n, p, s,f), humi(n, p, w1, w2)
    {
        dw=0;
    }
    void display()
    {
        // 加湿风扇--档位1
        cout << "加湿风扇--档位" << dw << endl;
        // 编号1001--功率1000W
        cout << "编号" << name << "--功率" << power << "W" << endl;
        cout << test(fang) << speed << "级" << endl;

        // 实际水容量3升--水量正常
        cout << "实际水容量" << w1 << "升--水量";
        if (alarm() == 1)
        {
            cout << "正常" << endl;
        }
        else if (alarm() == 3)
        {
            cout << "不足" << endl;
        }
        else
        {
            cout << "偏低" << endl;
        }
        //
    }
    void change(int s)
    {
        if (s < 0 || s > 3)
        {
            return;
        }
        dw = s;
        if (s == 0)
        {
            return;
        }
        if (s == 1)
        {
            speed = 1;
            fang = 0;
        }
        else
        {
            fang = 1;
            speed = s;
        }
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string name;
        int power, speed, fang, dw;
        float w1, w2;
        cin >> name >> power >> fang >> speed >> w1 >> w2 >> dw;
        humi_fan hf(name, power, speed, fang,w1, w2,dw);
        int dw1;
        cin >> dw1;
        hf.change(dw1);
        hf.display();
    }

    return 0;
}