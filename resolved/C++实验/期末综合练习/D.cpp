#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
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

class CSet
{
  private:
    vector<int> data;

  public:
    CSet() = default;

    CSet(const vector<int>& elements)
    {
        for (int elem : elements)
        {
            if (find(data.begin(), data.end(), elem) == data.end())
            {
                data.push_back(elem);
            }
        }
    }

    friend ostream& operator<<(ostream& os, const CSet& s)
    {
        for (auto it = s.data.begin(); it != s.data.end(); ++it)
        {
            if (it != s.data.begin())
            {
                os << " ";
            }
            os << *it;
        }
        return os;
    }

    CSet operator+(const CSet& other) const
    {
        CSet result = *this;
        for (int elem : other.data)
        {
            if (find(result.data.begin(), result.data.end(), elem) == result.data.end())//去重
            {
                result.data.push_back(elem);
            }
        }
        return result;
    }

    CSet operator-(const CSet& other) const
    {
        CSet result;
        for (int elem : this->data)
        {
            if (find(other.data.begin(), other.data.end(), elem) == other.data.end())
            {
                result.data.push_back(elem);
            }
        }
        return result;
    }

    CSet operator*(const CSet& other) const
    {
        CSet result;
        for (int elem : this->data)
        {
            if (find(other.data.begin(), other.data.end(), elem) != other.data.end())
            {
                result.data.push_back(elem);
            }
        }
        return result;
    }
};

int main()
{
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; ++t)
    {
        int nA, nB;
        cin >> nA;
        vector<int> elementsA(nA);
        for (int i = 0; i < nA; ++i)
        {
            cin >> elementsA[i];
        }

        cin >> nB;
        vector<int> elementsB(nB);
        for (int i = 0; i < nB; ++i)
        {
            cin >> elementsB[i];
        }

        CSet A(elementsA);
        CSet B(elementsB);

        CSet unionSet = A + B;
        CSet intersectionSet = A * B;
        CSet relativeComplementSet = (A - B) + (B - A);

        cout << "A:" << A << endl;
        cout << "B:" << B << endl;
        cout << "A+B:" << unionSet << endl;
        cout << "A*B:" << intersectionSet << endl;
        cout << "(A-B)+(B-A):" << relativeComplementSet << endl;

        if (t < testCases - 1)
        {
            cout << endl;
        }
    }

    return 0;
}