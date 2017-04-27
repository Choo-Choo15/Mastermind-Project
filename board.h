#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include "circles.h"
#include "circlesfeedback.h"

namespace Ui {
class board;
}

class board : public QMainWindow
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = 0);
    Circles *spaces[4][10];
    Circles *colors[8][1];
    CirclesFeedback *circlesFeedback[4][10];
    void setColors();
    void resetBoard();
    ~board();

private:
    Ui::board *ui;

private slots:
    void new_game();
    void exit();
    void open_Instructions();
    void about();
    void aboutQt();
    void on_submitButton_clicked();
    void on_clearButton_clicked();
};

#endif // BOARD_H
