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
template <class T> class Matrix
{
  private:
    T** a;
    int m, n;

  public:
    Matrix(int m, int n) : m(m), n(n)
    {
        a = new T*[m + 2];
        f(i, 1, m)
        {
            a[i] = new T[n + 2];
        }
    }
    Matrix(T** b, int x, int y)
    {
        m = x;
        n = y;
        a = new T*[m + 2];
        f(i, 1, m)
        {
            a[i] = new T[n + 2];
        }
        f(i, 1, m)
        {
            f(j, 1, n)
            {
                a[i][j] = b[i][j];
            }
        }
    }
    // 转置矩阵
    void transport()
    {
        T** b = new T*[n + 2];
        f(i, 1, n)
        {
            b[i] = new T[m + 2];
        }
        f(i, 1, m)
        {
            f(j, 1, n)
            {
                b[j][i] = a[i][j];
            }
        }
        f(i, 1, m)
        {
            delete[] a[i]; // 释放a[i]
        }
        delete[] a; // 释放a
        a = b;      // a指向b
        swap(m, n); // 交换m和n
    }
    void print()
    {
        f(i, 1, m)
        {
            f(j, 1, n)
            {
                if(j==1)
                {
                    cout << a[i][j];
                }
                else
                {
                    cout << " " << a[i][j];
                }
            }
            if (i < m)
            {
                cout << endl;
            }
        }
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        char type;
        cin >> type;
        int m, n;
        cin >> m >> n;
        if (type == 'I')
        {
            int** a = new int*[m + 2];
            f(i, 1, m)
            {
                a[i] = new int[n + 2];
                f(j, 1, n)
                {
                    cin >> a[i][j];
                }
            }
            Matrix<int> b(a, m, n);
            b.transport();
            b.print();
        }
        else if (type == 'C')
        {
            char** a = new char*[m + 2];
            f(i, 1, m)
            {
                a[i] = new char[n + 2];
                f(j, 1, n)
                {
                    cin >> a[i][j];
                }
            }
            Matrix<char> b(a, m, n);
            b.transport();
            b.print();
        }
        else
        {
            double** a = new double*[m + 2];
            f(i, 1, m)
            {
                a[i] = new double[n + 2];
                f(j, 1, n)
                {
                    cin >> a[i][j];
                }
            }
            Matrix<double> b(a, m, n);
            b.transport();
            b.print();
        }
        if (t >= 1)
        {
            cout << endl;
        }
    }

    return 0;
}