#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <string>

std::string get_number_from_word(std::string word){
    if(word=="one"){
        return "1";
    } else if(word=="two"){
        return "2";
    } else if(word=="three"){
        return "3";
    }
    else if(word=="four"){
        return "4";
    }
    else if(word=="five"){
        return "5";
    }
    else if(word=="six"){
        return "6";
    }
    else if(word=="seven"){
        return "7";
    }
    else if(word=="eight"){
        return "8";
    }
    else if(word=="nine"){
        return "9";
    } else{
        return word;
    }
}

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
    int id = 1;
    for (std::string line : inputs)
    {
        std::regex pattern("\\d|one|two|three|four|five|six|seven|eight|nine");
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
            std::string first_digit = get_number_from_word(matches.front());
            std::string last_digit = get_number_from_word(matches.back());
            std::string two_digits = first_digit + last_digit;
            std::cout <<id ++<< " two digits: "<< two_digits <<" string: "<<line<< std::endl;
            sum += stoi(two_digits);
        }
    }

    std::cout <<"sum: "<< sum << std::endl;
}