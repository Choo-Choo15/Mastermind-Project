#ifndef PLAYERGUESS_H
#define PLAYERGUESS_H
#include <string>
#include "playerguessfeedback.h"

class PlayerGuess
{
private:
    char guess[5];
public:
    PlayerGuess();
    PlayerGuessFeedBack FB;
    char* getGuess();
    void setGuess();
    bool checkPattern();
};
#endif // PLAYERGUESS_H
