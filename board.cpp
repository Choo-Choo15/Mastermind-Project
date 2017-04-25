#include "board.h"
#include "ui_board.h"
#include <QtGui>

board::board(QWidget *parent) : QWidget(parent), ui(new Ui::board)
{
    ui->setupUi(this);

    int y = 0;

    for (int r = 0; r < 10; r++)
    {
        int x = 0;
        for (int c = 0; c < 4; c++)
        {
            spaces[r][c] = new Circles(this);
            spaces[r][c]->setGeometry(x,y,64,64);
            x += 65;
        }
        y += 65;
    }
    int colorY = 0;
    for(int r = 0; r < 8; r++)
    {
        int colorX = 360;
        for(int c = 0; c < 1; c++)
        {
            colors[r][c] = new Circles(this);
            colors[r][c] -> setGeometry(colorX,colorY, 64, 64);
            colorX+=65;
        }
        colorY+=65;

    }
    setColors();


}

void board::setColors()
{
    colors[0][0]->setColor('R');
    colors[1][0]->setColor('N');
    colors[2][0]->setColor('P');
    colors[3][0]->setColor('G');
    colors[4][0]->setColor('Y');
    colors[5][0]->setColor('O');
    colors[6][0]->setColor('L');
    colors[7][0]->setColor('B');
    repaint();
}

void board::resetBoard()
{

}

board::~board()
{
    delete ui;
}
