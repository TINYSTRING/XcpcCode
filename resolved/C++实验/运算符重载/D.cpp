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
class MyMatrix
{
  private:
    int** data;
    int n;

  public:
    MyMatrix(){};
    MyMatrix(int n) : n(n)
    {
        data = new int*[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = new int[n];
        }
    }
    MyMatrix(int** m, int n) : n(n)
    {
        data = new int*[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                data[i][j] = m[i][j];
            }
        }
    }
    void set(int** m, int n)
    {
        this->n = n;
        data = new int*[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                data[i][j] = m[i][j];
            }
        }
    }
    ~MyMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    };
    MyMatrix& operator*=(MyMatrix& b)
    {
        MyMatrix temp(n); // 创建一个新的临时矩阵来存储结果
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.data[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    temp.data[i][j] += data[i][k] * b.data[k][j];
                }
            }
        }
        // 将结果复制回当前矩阵
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                data[i][j] = temp.data[i][j];
            }
        }
        return *this;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(j==n-1)
                {
                    cout << data[i][j];
                }
                else
                {
                    cout << data[i][j] << " ";
                }
            }
            if (i != n - 1)
            {
                cout << endl;
            }
        }
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c;
    cin >> c;
    int n;
    cin >> n;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    MyMatrix res(a, n);
    c--;
    while (c--)
    {
        int** b = new int*[n];
        for (int i = 0; i < n; i++)
        {
            b[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                cin >> b[i][j];
            }
        }
        MyMatrix temp(b, n);
        res *= temp;
    }
    res.print();
    return 0;
}