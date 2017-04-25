#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "circles.h"
#include "ui_board.h"

namespace Ui {
class board;
}

class board : public QWidget
{

private:
    Ui::board *ui;
    Q_OBJECT

public:
    explicit board(QWidget *parent = 0);
    Circles *spaces[4][10];
    Circles *colors[8][1];
    void setColors();
    void resetBoard();
    ~board();


};

#endif // BOARD_H
