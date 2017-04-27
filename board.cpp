#include "board.h"
#include "ui_board.h"

#include <QtWidgets>

board::board(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::board)
{
    ui->setupUi(this);

    connect(ui->actionNew_Game,SIGNAL(triggered()),this,SLOT(new_game()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(exit()));
    connect(ui->actionInstructions,SIGNAL(triggered()),this,SLOT(open_Instructions()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),this,SLOT(aboutQt()));

    int y = 0;

    for (int r = 0; r < 10; r++)
    {
        int x = 0;
        for (int c = 0; c < 4; c++)
        {
            spaces[r][c] = new Circles(this);
            spaces[r][c]->setGeometry(x,50+y,64,64);
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
            colors[r][c] -> setGeometry(colorX,50+colorY, 64, 64);
            colorX+=65;
        }
        colorY+=65;

    }
    setColors();


    for( int i = 0 ; i < 10 ; i++ )
    {
        for( int j = 0 ; j < 4 ; j++ )
        {
            circlesFeedback[j][i] = new CirclesFeedback(this);
            switch(j)
            {
            case 0:
                circlesFeedback[j][i]->setGeometry(280 + 5,50+ (i*65)+10,20,20);
                break;
            case 1:
                circlesFeedback[j][i]->setGeometry(280 + 5,50+ (i*65)+35,20,20);
                break;
            case 2:
                circlesFeedback[j][i]->setGeometry(280 + 30,50+ (i*65)+10,20,20);
                break;
            case 3:
                circlesFeedback[j][i]->setGeometry(280 + 30,50+ (i*65)+35,20,20);
            }
        }
    }


}

board::~board()
{
    delete ui;
}

void board::new_game()
{
    //reset game
    QMessageBox::about(this, tr("Test"),
                tr("Clicked New Game"));
}

void board::exit()
{
    board::close();
}

void board::open_Instructions()
{
    QMessageBox::about(this, tr("Instructions Menu"),
                tr("Instructions.......when project is done..."));
}

void board::about()
{
    QMessageBox::about(this, tr("About Menu"),
            tr("Mastermind Game\t\nMade us c++ and Qt \nBy: \n  Alison Cerny\n  Thomas Everson\n  Jaime Minan"));
}

void board::aboutQt()
{
    QMessageBox::aboutQt(this);
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


void board::on_submitButton_clicked()
{
    //HOW: right click on the button it the Qt Designer ui then clicked "Go to slot"
    //add button function
    QMessageBox::about(this, tr("Test"),
                tr("Clicked Submit"));
}

void board::on_clearButton_clicked()
{
    //add button function
    QMessageBox::about(this, tr("Test"),
                tr("Clicked Clear"));
}
