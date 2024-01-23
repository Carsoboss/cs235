#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void printLines(std::istream &in, int n)
{
    std::string line;
    for (int i = 0; i < n && std::getline(in, line); ++i)
    {
        std::cout << line << std::endl;
    }
}

int main(int argc, char *argv[])
{
    int n = 10; // default number of lines

    if (argc > 3)
    {
        std::cerr << "Usage: ./head [-n] [file]\n";
        return 1;
    }

    if (argc == 1)
    {
        printLines(std::cin, n);
    }
    else if (argc == 2)
    {
        std::string arg1 = argv[1];
        if (arg1[0] == '-')
        {
            n = std::atoi(arg1.substr(1).c_str());
            printLines(std::cin, n);
        }
        else
        {
            std::ifstream file(arg1);
            if (!file)
            {
                std::cerr << "ERROR: can't open " << arg1 << std::endl;
                return 1;
            }
            printLines(file, n);
        }
    }
    else
    {
        n = std::atoi(argv[1] + 1);
        std::ifstream file(argv[2]);
        if (!file)
        {
            std::cerr << "ERROR: can't open " << argv[2] << std::endl;
            return 1;
        }
        printLines(file, n);
    }

    return 0;
}
