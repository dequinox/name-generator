#ifndef GENERATOR_H
#define GENERATOR_H

#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

class Generator
{
    private:
        std::map<std::string, std::map<std::string, int> > chain;
        std::vector<std::string> dictionary;

        std::string selectRandomItem(std::string category);
    public:
        Generator(std::vector<std::string> dict, int n);
        std::string generate(int max_len);
};

#endif /* GENERATOR_H */
