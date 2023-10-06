#include <iostream>
using ll = long long;
ll n;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (1)
    {
        std::cin >> n;
        if (n == -1)
            return 0;
        ll a = 1, b = 0;
        ll a1 = 0, b1 = 0;
        for (ll i = 1; i <= n; i++)
        {
            a1 = b + 1;
            b1 = b + a;
            a = a1;
            b = b1;
        }
        std::cout << b << ' ' << a + b << '\n';
    }
    return 0;
}