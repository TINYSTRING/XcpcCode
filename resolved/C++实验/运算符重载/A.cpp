#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define lcm(a,b) (a*b)/gcd(a,b)
#define all(a) a.begin(),a.end()
#define mem(a,x) memset(a,x,sizeof(a))
#define f(i,s,e) for(int i=s;i<=e;i++)
#define ff(i,s,e) for(int i=s;i>=e;i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define maxn (ll)(2e5+5000)
#define INF LONG_LONG_MAX
using namespace std;
//set<int>::iterator it;
class Fraction
{
private:
    int fz, fm;
    int commonDivisor(); // 计算最大公约数
    void contracted(); // 分数化简
public:
    Fraction(int = 0, int = 1);
    Fraction(Fraction&);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    void set(int = 0, int = 1);
    void display();
};
Fraction::Fraction(int fz, int fm)
{
    this->fz = fz;
    this->fm = fm;
    contracted();
}
Fraction::Fraction(Fraction& f)
{
    this->fz = f.fz;
    this->fm = f.fm;
}
int Fraction::commonDivisor()
{
    int a = fz, b = fm, c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
void Fraction::contracted()
{
    //int cd = commonDivisor();
    //fz /= cd;
    //fm /= cd;
    if(fm < 0)
    {
        fz = -fz;
        fm = -fm;
    }
}
Fraction Fraction::operator+(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm + f.fz * fm;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}
Fraction Fraction::operator-(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm - f.fz * fm;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}
Fraction Fraction::operator*(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fz;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}

Fraction Fraction::operator/(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm;
    temp.fm = fm * f.fz;
    temp.contracted();
    return temp;
}
void Fraction::set(int fz, int fm)
{
    this->fz = fz;
    this->fm = fm;
    contracted();
}
void Fraction::display()
{
    cout<<"fraction="<<fz<<"/"<<fm<<endl;
}
signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Fraction f1(a,b), f2(c,d);
    (f1+f2).display();
    (f1-f2).display();
    (f1*f2).display();
    (f1/f2).display();
    return 0;
}