#include <iostream>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ans += pre[j] ^ pre[i - 1];
        }
    }
    std::cout << ans << '\n';

    return 0;
}