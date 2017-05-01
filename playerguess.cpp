#include "playerguess.h"
#include "patterngenerator.h"

#include <iostream>//for testing purposes only

PlayerGuess::PlayerGuess()
{
    PatternGenerator currentPattern;
    answer = currentPattern.getPattern();
    guess = "    ";
}

std::string PlayerGuess::getGuess()
{
    return guess;
}

void PlayerGuess::setGuess(std::string inGuess)
{
    for(int i = 0; i<4; i++)
    {
        guess[i] = inGuess[i];
    }
}

void PlayerGuess::checkPattern()
{
    for(int i = 0; i<5; i++)
    {
        std::size_t inString = answer.find(guess[i]);//found at http://www.cplusplus.com/reference/string/string/find/
        if(inString!=std::string::npos)
        {
            if(guess[i] == answer[i])
            {
                //code to make black pin in position i
                std::cout<<" Black pin" << std::endl;
            }
            else
            {
                //code to make white pin in position i
                std::cout<<" White pin" << std::endl;

            }

        }
        else
        {
            //code to make light gray pin at position i
            std::cout<<" No pin" << std::endl;
        }

    }
}

