#include <iostream>
#include <cstdlib> // For atoi

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <start> <end> <divisor>\n";
        return 1;
    }

    int start = std::atoi(argv[1]);
    int end = std::atoi(argv[2]);
    int divisor = std::atoi(argv[3]);

    if (divisor == 0)
    {
        std::cerr << "Error: Divisor cannot be 0.\n";
        return 1;
    }

    if (start <= end)
    {
        for (int i = start; i <= end; ++i)
        {
            if (i % divisor == 0)
            {
                std::cout << i << std::endl;
            }
        }
    }
    else
    {
        for (int i = start; i >= end; --i)
        {
            if (i % divisor == 0)
            {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}
