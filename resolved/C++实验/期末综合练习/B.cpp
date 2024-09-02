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

class Node2D
{
public:
    string location;
};

class Body : virtual public Node2D
{
public:
    int maxHealth;
    int health;
    int defense;
    Body(int mh, int h, int d): maxHealth(mh), health(h), defense(d) {}
};

class Weapon : virtual public Node2D
{
public:
    string weaponName;
    int damage;
    Weapon(string w_name, int dmg): weaponName(w_name), damage(dmg) {}
};

class Player : public Body, public Weapon
{
public:
    string name;
    Player(string loc, string n, int mh, int d, string w_name, int attack): 
        Node2D{loc}, Body{mh, mh, d}, Weapon{w_name, attack}, name{n} {}
    // Player(string loc, string n, int mh, int d, string w_name, int attack):
    // {
    //     location = loc;
    //     name = n;
    //     maxHealth = mh;
    //     health = mh;
    //     defense = d;
    //     weaponName = w_name;
    //     damage = attack;
    // }
    void attack(Player &p)
    {
        cout << name << " deal " << damage-p.defense << " damage to " << p.name << endl;
        p.health -= (damage-p.defense);
        if (p.health <= 0)
        {
            cout << name << " defeated " << p.name << " by " << weaponName << " in " << location << endl;
        }
        else
        {
            cout << p.name << " still have " << p.health << " health" << endl;
        }
    }
};

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string location;
    cin >> location;
    string n1;
    int mh, d;
    string w_name;
    int attack;

    cin >> n1 >> mh >> d >> w_name >> attack;
    Player p1(location, n1, mh, d, w_name, attack);
    
    cin >> n1 >> mh >> d >> w_name >> attack;
    Player p2(location, n1, mh, d, w_name, attack);

    int flag = 1;
    while (p1.health > 0 && p2.health > 0)
    {
        if (flag & 1)
        {
            p1.attack(p2);
        }
        else
        {
            p2.attack(p1);
        }
        flag ^= 1;
        cout<<endl;
    }

    return 0;
}
