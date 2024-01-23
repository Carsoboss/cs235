#include <iostream>
#include <string>

void sort(std::string &a, std::string &b, std::string &c)
{
    if (a > b)
        std::swap(a, b);
    if (b > c)
        std::swap(b, c);
    if (a > b)
        std::swap(a, b);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sort <string1> <string2> <string3>\n";
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}
