#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int long long
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
class CPoint
{
private:
    int x,y;
public:
    CPoint(int x = 0, int y = 0) : x(x), y(y) {}
    CPoint(const CPoint &p) : x(p.x), y(p.y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    friend ostream &operator<<(ostream &os, const CPoint &p)
    {
        os <<p.x << " " << p.y;
        return os;
    }
};
class CRectangle
{
private:
    CPoint lestPoint, rightPoint;
public:
    CRectangle(int x1, int y1, int x2, int y2) : lestPoint(x1, y1), rightPoint(x2, y2) {}
    bool operator > (const CRectangle &rect) const
    {
        //判断是否包含rect
        return (lestPoint.getX() <= rect.lestPoint.getX() && lestPoint.getY() >= rect.lestPoint.getY() && rightPoint.getX() >= rect.rightPoint.getX() && rightPoint.getY() <= rect.rightPoint.getY());
    }
    bool operator >(const CPoint &p) const
    {
        return (lestPoint.getX() <= p.getX() && lestPoint.getY() >= p.getY() && rightPoint.getX() >= p.getX() && rightPoint.getY() <= p.getY());//判断是否包含点p
    }
    bool operator == (const CRectangle &rect) const
    {
        //判断是否相等
        return (lestPoint.getX() == rect.lestPoint.getX() && lestPoint.getY() == rect.lestPoint.getY() && rightPoint.getX() == rect.rightPoint.getX() && rightPoint.getY() == rect.rightPoint.getY());
    }
    bool operator * (const CRectangle &rect) const
    {
        //判断是否相交
        return !(rightPoint.getX() < rect.lestPoint.getX() || rightPoint.getY() > rect.lestPoint.getY() || lestPoint.getX() > rect.rightPoint.getX() || lestPoint.getY() < rect.rightPoint.getY());
    }
    operator int() const
    {
        //返回面积
        return (rightPoint.getX() - lestPoint.getX()) * (lestPoint.getY()- rightPoint.getY());
    }
    friend ostream &operator<<(ostream &os, const CRectangle &rect)
    {
        os << rect.lestPoint << " " << rect.rightPoint;
        return os;
    }
};
int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}