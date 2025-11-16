#include <iostream>
#include <string>
#include <string_view>

void print(std::string s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string_view sv{ "balloon" };

    sv.remove_suffix(3);

    // print(sv); // помилка компіляції: неявна конвертація заборонена

    std::string str{ sv }; // явна конвертація

    print(str); // ок

    print(static_cast<std::string>(sv)); // ок

    return 0;
}