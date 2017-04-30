#include "patterngenerator.h"
#include <string>
#include "time.h"
PatternGenerator::PatternGenerator()
{
    pattern = "    ";
}

std::string PatternGenerator::getPattern()
{
    return pattern;
}

void PatternGenerator::setPattern()
{
    std::srand(time(0));
    for(int i = 0; i<4; i++)
    {
        pattern[i] = choices[rand() % choices.length()];
    }

}

