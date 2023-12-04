#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

std::string get_number_from_line(std::string line)
{
    std::regex pattern("\\d+");
    std::smatch matches;
    std::string number;
    if (std::regex_search(line, matches, pattern))
    {
        number = matches.str();
    }
    return number;
}

std::vector<int> get_colors_count(std::string line, std::string color)
{
    std::regex pattern("\\d+ " + color);
    std::regex_iterator<std::string::iterator> rit(line.begin(), line.end(), pattern);
    std::regex_iterator<std::string::iterator> rend;
    std::vector<int> matches;

    while (rit != rend)
    {
        std::string number = get_number_from_line(rit->str());
        matches.push_back(stoi(number));
        ++rit;
    }
    return matches;
}

bool are_balls_within_limits(std::vector<int> balls, int maximal)
{
    bool is_within = true;
    for (auto ball : balls)
    {
        if (ball > maximal)
        {
            is_within = false;
            break;
        }
    }
    return is_within;
}

bool is_color_within_limits(std::string line,
                            std::string color, int max)
{
    auto color_count = get_colors_count(line, color);
    return are_balls_within_limits(color_count, max);
}

bool is_line_within_limits(std::string line)
{
    return is_color_within_limits(line, "red", 12) &&
           is_color_within_limits(line, "green", 13) &&
           is_color_within_limits(line, "blue", 14);
}

int get_id_from_line(std::string line){
    std::regex pattern("Game \\d+:");
    std::smatch matches;
    std::string number;
    std::string id;
    if (std::regex_search(line, matches, pattern))
    {
        id = get_number_from_line(matches.str());
    }
    return std::stoi(id);
}

int main()
{
    std::ifstream file("input");

    unsigned int id_sum = 0;

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {

            if (is_line_within_limits(line)){
                id_sum += get_id_from_line(line);
            }
        }
    }
    file.close();

    std::cout << "Suma id: " << id_sum << std::endl;

    return 0;
}