#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <string>

int main()
{

    std::vector<std::string> inputs;

    std::ifstream file("input");

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            inputs.push_back(line);
        }
    }
    file.close();

    unsigned int sum = 0;
    for (std::string line : inputs)
    {
        std::regex pattern("\\d");
        std::regex_iterator<std::string::iterator> rit(line.begin(), line.end(), pattern);
        std::regex_iterator<std::string::iterator> rend;
        std::vector<std::string> matches;

        while (rit != rend)
        {
            matches.push_back(rit->str());
            ++rit;
        }

        if (matches.size() > 0)
        {
            std::string first_digit = matches.front();
            std::string last_digit = matches.back();
            std::string two_digits = first_digit + last_digit;
            sum += stoi(two_digits);
        }
    }

    std::cout << sum << std::endl;
}