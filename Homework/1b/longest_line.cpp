#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./longest_line <filename>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string line, longestLine;
    size_t maxWords = 0;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        size_t wordCount = 0;
        std::string word;

        while (iss >> word)
        {
            ++wordCount;
        }

        if (wordCount > maxWords)
        {
            maxWords = wordCount;
            longestLine = line;
        }
    }

    file.close();
    std::cout << longestLine << std::endl;
    return 0;
}
