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
#define maxn (ll)(2e5+5000)
#define INF LONG_LONG_MAX
using namespace std;

#define MAXN 100010

int n, m;
int a[MAXN];

struct Segment_Tree {
    ll sum, add, mul;
    int l, r;
}s[MAXN * 4];

void update(int pos) {
    s[pos].sum = s[pos << 1].sum + s[pos << 1 | 1].sum;
    return;
}

void pushdown(int pos) {
    s[pos << 1].sum = s[pos << 1].sum * s[pos].mul + s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1);
    s[pos << 1 | 1].sum = s[pos << 1 | 1].sum * s[pos].mul + s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1);
    
    s[pos << 1].mul = s[pos << 1].mul * s[pos].mul;
    s[pos << 1 | 1].mul = s[pos << 1 | 1].mul * s[pos].mul;
    
    s[pos << 1].add = s[pos << 1].add * s[pos].mul + s[pos].add;
    s[pos << 1 | 1].add = s[pos << 1 | 1].add * s[pos].mul + s[pos].add;
        
    s[pos].add = 0;
    s[pos].mul = 1;
    return; 
}

void build_tree(int pos, int l, int r) {
    s[pos].l = l;
    s[pos].r = r;
    s[pos].mul = 1;
    
    if (l == r) {
        s[pos].sum = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build_tree(pos << 1, l, mid);
    build_tree(pos << 1 | 1, mid + 1, r);
    update(pos);
    return;
}

void ChangeMul(int pos, int x, int y, int k) {
    if (x <= s[pos].l && s[pos].r <= y) {
        s[pos].add = s[pos].add * k;
        s[pos].mul = s[pos].mul * k;
        s[pos].sum = s[pos].sum * k;
        return;
    }
    
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid) ChangeMul(pos << 1, x, y, k);
    if (y > mid) ChangeMul(pos << 1 | 1, x, y, k);
    update(pos);
    return;
}

void ChangeAdd(int pos, int x, int y, int k) {
    if (x <= s[pos].l && s[pos].r <= y) {
        s[pos].add = s[pos].add + k;
        s[pos].sum = s[pos].sum + k * (s[pos].r - s[pos].l + 1);
        return;
    }
    
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid) ChangeAdd(pos << 1, x, y, k);
    if (y > mid) ChangeAdd(pos << 1 | 1, x, y, k);
    update(pos);
    return;
}

ll AskRange(int pos, int x, int y) {
    if (x <= s[pos].l && s[pos].r <= y) {
        return s[pos].sum;
    }
    
    pushdown(pos);
    ll val = 0;
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid) val = val + AskRange(pos << 1, x, y);
    if (y > mid) val = val + AskRange(pos << 1 | 1, x, y);
    return val;
}

signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build_tree(1, 1, n);
    
    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            int k;
            cin >> k;
            ChangeMul(1, x, y, k);
        }
        if (opt == 2) {
            int k;
            cin >> k;
            ChangeAdd(1, x, y, k);
        }
        if (opt == 3) {
            cout << AskRange(1, x, y) << endl;
        }
    }
    
    return 0;
}