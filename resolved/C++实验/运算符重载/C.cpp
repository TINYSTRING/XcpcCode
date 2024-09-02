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
class Vector
{
  private:
    int vec[5];

  public:
    Vector(int v[]);
    Vector();
    Vector(const Vector& obj);
    Vector operator+(const Vector& obj);
    Vector operator-(const Vector& obj);
    void print();
};
Vector::Vector(int v[])
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = v[i];
    }
}
Vector::Vector()
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = 0;
    }
}
Vector::Vector(const Vector& obj)
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = obj.vec[i];
    }
}
Vector Vector::operator+(const Vector& obj)
{
    Vector temp;
    for (int i = 0; i < 5; i++)
    {
        temp.vec[i] = vec[i] + obj.vec[i];
    }
    return temp;
}
Vector Vector::operator-(const Vector& obj)
{
    Vector temp;
    for (int i = 0; i < 5; i++)
    {
        temp.vec[i] = vec[i] - obj.vec[i];
    }
    return temp;
}
void Vector::print()
{
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int v1[6];
    int v2[6];
    f(i,0,4)
    {
        cin>>v1[i];
    }
    f(i,0,4)
    {
        cin>>v2[i];
    }
    Vector a(v1);
    Vector b(v2);
    (a+b).print();
    (a-b).print();

    return 0;
}