#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H


class PatternGenerator
{
private:
    char pattern[5];
public:
    PatternGenerator();
    char getPattern();//needs a pointer
    void setPattern();
};

#endif // PATTERNGENERATOR_H
