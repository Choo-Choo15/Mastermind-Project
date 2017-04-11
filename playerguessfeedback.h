#ifndef PLAYERGUESSFEEDBACK_H
#define PLAYERGUESSFEEDBACK_H
class PlayerGuessFeedBack
{
private:
    int whitePeg;
    int blackPeg;
public:
    PlayerGuessFeedBack();
    QString getPlayerGuess(playerguess);//might not be right
    int getWhitePeg();
    int getBlackPeg();
    void setWhitePeg();
    void setBlackPeg();
    void setNextRow();
};
#endif // PLAYERGUESSFEEDBACK_H
