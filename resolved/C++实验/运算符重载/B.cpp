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
class Complex
{
private:
    float real, image;
public:
    Complex(float x = 0, float y = 0);
    friend Complex operator+(Complex&, Complex&);
    friend Complex operator-(Complex&, Complex&);
    friend Complex operator*(Complex&, Complex&);
    void show();
};
Complex::Complex(float x, float y)
{
    real = x;
    image = y;
}
Complex operator+(Complex& a, Complex& b)
{
    Complex temp;
    temp.real = a.real + b.real;
    temp.image = a.image + b.image;
    return temp;
}
Complex operator-(Complex& a, Complex& b)
{
    Complex temp;
    temp.real = a.real - b.real;
    temp.image = a.image - b.image;
    return temp;
}
Complex operator*(Complex& a, Complex& b)
{
    Complex temp;
    temp.real = a.real * b.real - a.image * b.image;
    temp.image = a.real * b.image + a.image * b.real;
    return temp;
}
void Complex::show()
{
    cout<<"Real="<<real<<" Image="<<image<<endl;
}

signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    float r1,i1;
    cin>>r1>>i1;
    Complex c1(r1,i1);
    float r2,i2;
    cin>>r2>>i2;
    Complex c2(r2,i2);
    (c1+c2).show();
    (c1-c2).show();
    (c1*c2).show();

    return 0;
}