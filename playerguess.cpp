#include "playerguess.h"
#include "patterngenerator.h"
#include "board.h"
#include <QtWidgets>
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

void PlayerGuess::checkPattern(CirclesFeedback *boxOfCircles[10][4], int numOfGuesses)
{
    //if the guess and the answer are the same, winning message
    if(guess==answer)
    {
        QMessageBox msgBox;
        msgBox.setText("Winner! You guessed the pattern!");
        msgBox.exec();
    }

    //if the guess and answer are not the same, and they have reached the maximum number of guesses, losing message
    if(guess!=answer && numOfGuesses >= 9)
    {
        QMessageBox msgBox;
        msgBox.setText("You Lost! You didn't guess the pattern :(");
        msgBox.exec();
    }

    //color the pegs according to correct and incorrect guesses
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
                    boxOfCircles[numOfGuesses][1]->setColor('B');
                }
                else if(i==1)
                {
                    boxOfCircles[numOfGuesses][0]->setColor('B');
                }
                else if(i==2)
                {
                    boxOfCircles[numOfGuesses][3]->setColor('B');
                }
                else if(i==3)
                {
                    boxOfCircles[numOfGuesses][2]->setColor('B');
                }
            }
            else
            {
                //code to make white pin in position i
                if(i==0)
                {
                    boxOfCircles[numOfGuesses][1]->setColor('W');
                }
                else if(i==1)
                {
                    boxOfCircles[numOfGuesses][0]->setColor('W');
                }
                else if(i==2)
                {
                    boxOfCircles[numOfGuesses][3]->setColor('W');
                }
                else if(i==3)
                {
                    boxOfCircles[numOfGuesses][2]->setColor('W');
                }

            }

        }
        else
        {
            if(i==0)
            {
                boxOfCircles[numOfGuesses][1]->setColor('L');
            }
            else if(i==1)
            {
                boxOfCircles[numOfGuesses][0]->setColor('L');
            }
            else if(i==2)
            {
                boxOfCircles[numOfGuesses][3]->setColor('L');
            }
            else if(i==3)
            {
                boxOfCircles[numOfGuesses][2]->setColor('L');
            }
        }

    }
}

