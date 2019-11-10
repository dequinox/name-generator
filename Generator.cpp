#include "Generator.h"

Generator::Generator(std::vector<std::string> dict, int n) : dictionary(dict)
{
    for (auto name : dictionary)
    {
        for (int i = 0; i < name.length() - n; i++)
        {
            std::string segment = name.substr(i, n);

            if (i == 0)
                chain["_initials"][segment]++;

            if (i + 1 < name.size() - n)
            {
                std::string next = name.substr(i + 1, n);
                chain[segment][next]++;
            }
        }
    }
}


std::string Generator::selectRandomItem(std::string segment)
{
    int sum = 0;
    for (auto const& item : chain[segment])
        sum += item.second;

    if (sum != 0)
    {
        int random = rand() % sum;
        for (auto const& item : chain[segment])
        {
            random -= item.second;
            if (random <= 0)
                return item.first;
        }
    }

    return ".";
}

std::string Generator::generate(int max_len)
{
    std::string segment = selectRandomItem("_initials");
    std::string result = segment;

    while (result.length() < max_len)
    {
        segment = selectRandomItem(segment);
        if (segment == ".")
            break;

        result += segment[segment.size() - 1];
    }


    return result;
}


