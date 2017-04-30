#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H
#include <string>

class PatternGenerator
{
private:
    std::string pattern;
    std::string choices = "RNPGYOLB";
public:
    PatternGenerator();
    std::string getPattern();//needs a pointer
    void setPattern();
};

#endif // PATTERNGENERATOR_H
