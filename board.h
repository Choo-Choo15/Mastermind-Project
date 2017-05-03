#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "circles.h"
#include "circlesfeedback.h"
#include "playerguess.h"

namespace Ui {
class board;
}

class board : public QMainWindow
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = 0);
    PlayerGuess guess;
    Circles *spaces[10][4];
    CirclesFeedback *circlesFeedback[10][4];
    void resetBoard();
    void getCurrentSpace();
    void setChecked(int inRow);
    ~board();

private:
    Ui::board *ui;
    int row = 0;
    int column = 0;
    int numOfGuesses = 0;

private slots:
    void new_game();
    void exit();
    void open_Instructions();
    void about();
    void aboutQt();
    void on_submitButton_clicked();
    void on_clearButton_clicked();
    void on_blueButton_clicked();
    void on_redButton_clicked();
    void on_yellowButton_clicked();
    void on_greenButton_clicked();
    void on_purpleButton_clicked();
    void on_orangeButton_clicked();
    void on_whiteButton_clicked();
    void on_blackButton_clicked();
};

#endif // BOARD_H

