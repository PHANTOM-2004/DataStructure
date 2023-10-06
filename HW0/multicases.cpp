#include <iostream>
#include <string>
#include <vector>

std::vector<int> Ans;
std::string str;

int main()
{
    while (1)
    {
        getline(std::cin, str);
        if (str[0] == '#')
            break;
        int ans = 0;
        const int l = str.length();
        for (int i = 0; i < l; i++)
        {
            const char ch = str[i];
            if (ch != ' ')
                ans += (ch - 'A' + 1) * (i + 1);
        }
        Ans.push_back(ans);
    }
    for (auto iter : Ans)
        std::cout << iter << '\n';
    return 0;
}