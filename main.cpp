#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Generator.h"

std::vector<std::string> dictionary;

void load(std::string filename, std::vector<std::string> &dict)
{
    std::ifstream file(filename);

    while (file.good())
    {
        std::string name;
        file >> name;
        dictionary.push_back(name);
    }

    dictionary.resize(dictionary.size() - 1);

    file.close();
}

int main()
{
    load("dictionary.txt", dictionary);

    int order, len;
    std::cout << "INPUT SEGMENT ORDER : ";
    std::cin >> order;
    std::cout << "INPUT LENGTH OF A NAME : ";
    std::cin >> len;

    Generator gen(dictionary, order);
    srand (time(NULL));

    for (int i = 0; i < 10; i++)
        std::cout << gen.generate(len) << std::endl;
    return 0;
}
