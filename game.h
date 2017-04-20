#ifndef GAME_H
#define GAME_H
#include "patterngenerator.h"
#include "playerguess.h"
#include <string>

class Game
{
public:
    Game();
    int numGuesses;
    PlayerGuess playerGuess;
    PatternGenerator patternGenerator;
    void runGame();
    //QString gameOutCome();

};

#endif // GAME_H
