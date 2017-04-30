#ifndef PLAYERGUESS_H
#define PLAYERGUESS_H
#include <string>
#include "playerguessfeedback.h"

class PlayerGuess
{
private:
    std::string guess;
    std::string answer;
public:
    PlayerGuess();
    PlayerGuessFeedBack FB;
    void setGuess(std::string inGuess);
    std::string getGuess();
    bool checkPattern();
};
#endif // PLAYERGUESS_H
