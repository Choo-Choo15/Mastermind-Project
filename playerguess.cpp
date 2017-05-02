#include "playerguess.h"
#include "patterngenerator.h"
#include "board.h"

#include <iostream>//for testing purposes only

PlayerGuess::PlayerGuess()
{
    PatternGenerator currentPattern;
    currentPattern.setPattern();
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

void PlayerGuess::checkPattern(CirclesFeedback *boxOfCircles[10][4])
{
    for(int i = 0; i<4; i++)
    {
        std::size_t inString = answer.find(guess[i]);//found at http://www.cplusplus.com/reference/string/string/find/
        if(inString!=std::string::npos)
        {
            if(guess[i] == answer[i])
            {
                //code to make black pin in position i
                if(i==0)
                {
                    boxOfCircles[0][0]->setColor('B');
                }
                else if(i==1)
                {
                    boxOfCircles[0][1]->setColor('B');
                }
                else if(i==2)
                {
                    boxOfCircles[1][0]->setColor('B');
                }
                else if(i==3)
                {
                    boxOfCircles[1][1]->setColor('B');
                }

                std::cout<<" Black pin" << std::endl;
            }
            else
            {
                //code to make white pin in position i
                if(i==0)
                {
                    boxOfCircles[0][0]->setColor('W');
                }
                else if(i==1)
                {
                    boxOfCircles[0][1]->setColor('W');
                }
                else if(i==2)
                {
                    boxOfCircles[1][0]->setColor('W');
                }
                else if(i==3)
                {
                    boxOfCircles[1][1]->setColor('W');
                }
                std::cout<<" White pin" << std::endl;

            }

        }
        else
        {
            boxOfCircles[0][i]->setColor('L');
            std::cout<<" No pin" << std::endl;
        }

    }
}

