#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
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

class Book
{
  public:
    string name;
    string author;
    double price;
    string publisher;

    Book() : name(""), author(""), price(0.0), publisher("")
    {
    }

    friend istream& operator>>(istream& is, Book& book);
    friend ostream& operator<<(ostream& os, const Book& book);
    friend void findTopTwo(Book* books, int n, int& max1Idx, int& max2Idx);
};

istream& operator>>(istream& is, Book& book)
{
    string priceStr;
    getline(is, book.name, ',');
    getline(is, book.author, ',');
    getline(is, priceStr, ',');
    book.price = stod(priceStr);
    getline(is, book.publisher);
    return is;
}

ostream& operator<<(ostream& os, const Book& book)
{
    os << book.name << endl;
    os << book.author << endl;
    os << fixed << setprecision(2) << book.price << endl;
    os << book.publisher;
    return os;
}

void findTopTwo(Book* books, int n, int& max1Idx, int& max2Idx)
{
    if (n == 0)
        return;
    max1Idx = 0;
    max2Idx = n > 1 ? 1 : 0;

    if (n > 1 && books[1].price > books[0].price)
    {
        max1Idx = 1;
        max2Idx = 0;
    }

    for (int i = 2; i < n; ++i)
    {
        if (books[i].price > books[max1Idx].price)
        {
            max2Idx = max1Idx;
            max1Idx = i;
        }
        else if (books[i].price > books[max2Idx].price)
        {
            max2Idx = i;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Book* books = new Book[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> books[i];
        }
        int max1Idx, max2Idx;
        findTopTwo(books, n, max1Idx, max2Idx);

        cout << books[max1Idx] << endl;
        cout<<endl;
        cout << books[max2Idx] << endl;

        delete[] books;
    }

    return 0;
}