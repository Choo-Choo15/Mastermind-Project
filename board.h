#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "circles.h"
#include "circlesfeedback.h"
#include "patterngenerator.h"

namespace Ui {
class board;
}

class board : public QMainWindow
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = 0);
    PatternGenerator pattern;
    Circles *spaces[4][10];
    //Circles *colors[8][1];
    CirclesFeedback *circlesFeedback[4][10];
    //void setColors();
    void resetBoard();
    void getCurrentSpace();
    ~board();

private:
    Ui::board *ui;
    int row = 0; //i tried to make a pointer that would return the memory location of the specific space but I gave up.
    int column = 0;

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

