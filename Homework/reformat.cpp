#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./reformat <input_file> <output_file>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string firstName, lastName;
    int points;
    double factor;

    while (inputFile >> firstName >> lastName >> points >> factor)
    {
        outputFile << lastName << ", " << firstName << ": " << points * factor << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
