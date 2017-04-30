#include "playerguess.h"
#include "patterngenerator.h"

PlayerGuess::PlayerGuess()
{
    PatternGenerator currentPattern;
    answer = currentPattern.getPattern();
}

std::string PlayerGuess::getGuess()
{
    return guess;
}

void PlayerGuess::setGuess(std::string inGuess)
{
    for(int i = 0; i<5; i++)
    {
        guess[i] = inGuess[i];
    }
}

bool PlayerGuess::checkPattern()
{
    for(int i = 0; i<6; i++)
    {
        std::size_t inString = answer.find(guess[i]);//found at http://www.cplusplus.com/reference/string/string/find/
        if(inString!=std::string::npos)
        {
            if(guess[i] == answer[i])
            {
                //code to make white pin in position i
                return true;
            }
            else
            {
                //code to make white pin in position i
                return true;
            }

        }
        else
        {
            //code to make light gray pin at position i
            return false;
        }
    }
}

