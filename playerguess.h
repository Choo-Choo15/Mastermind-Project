#ifndef PLAYERGUESS_H
#define PLAYERGUESS_H
#include <string>
#include "playerguessfeedback.h"
#include "circlesfeedback.h"

class PlayerGuess
{
private:
    std::string guess;
    std::string answer;
public:
    PlayerGuess();
    void setGuess(std::string inGuess);
    std::string getGuess();
    void checkPattern(CirclesFeedback *boxOfCircles[10][4]);
};
#endif // PLAYERGUESS_H
