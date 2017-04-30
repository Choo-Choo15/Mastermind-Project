#include "board.h"
#include "ui_board.h"
#include "circles.h"
#include "patterngenerator.h"
#include <QPainter>

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
    new_game();//this and commented section do same thing. Intial game works but new game breaks it.
    //    resetBoard();//moved code to reset board so that we can call new game.
    //    pattern.setPattern();
}

board::~board()
{
    delete ui;
}

void board::new_game()//does not work how it is supposed to. It just breaks everything...
{
  resetBoard();
  pattern.setPattern();
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

void board::resetBoard()
{
    int y = 0;

    for (int r = 0; r < 10; r++)
    {
        int x = 0;
        for (int c = 0; c < 4; c++)
        {
            spaces[r][c] = new Circles(this);
            spaces[r][c]->setColor(0); //added to try and stop the memory access problem.... run through debugger add colors until first 4 rows full you will see.
            spaces[r][c]->setGeometry(x,50+y,64,64);
            x += 65;
        }
        y += 65;
    }

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

    row = 0;
    column = 0;
    repaint();
}

void board::getCurrentSpace()
{
    char c = 'i';
    int i = 0;
    int j = 0;
    for(; i < 10; i++)
    {
        for(; j<4; j++)
        {
            c = spaces[i][j]->getColor();
            if(c == 0)
                break;
        }
        if(c == 0)
            break;
        j=0;
    }
    row = i;
    column = j;
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
    if(spaces[0][0]->getColor()==0)
    {
        QMessageBox::about(this,tr("Undo"), tr("Nothing to Undo"));
    }
    else
    {
        char c = 'i';
        int i = 0;
        int j = 0;
        for(; i < 10; i++)
        {
            for(; j<4; j++)
            {
                c = spaces[i][j]->getColor();
                if(c == 0)
                    break;
            }
            if(c == 0)
                break;
            j=0;
        }
        int rw = i;
        int col = j-1;
        if(col == -1)
        {
            col = 3;
            rw = i-1;
        }
        spaces[rw][col]->setColor(0);
        repaint();
    }
}

void board::on_blueButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('N');
    repaint();
}

void board::on_redButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('R');
    repaint();
}

void board::on_yellowButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('Y');
    repaint();
}

void board::on_greenButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('G');
    repaint();
}

void board::on_purpleButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('P'); //shows up as pink.... see circles.cpp
    repaint();
}

void board::on_orangeButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('O');//shows up as darkRed.... see circles.cpp
    repaint();
}

void board::on_whiteButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('W');
    repaint();
}

void board::on_blackButton_clicked()
{
    getCurrentSpace();
    spaces[row][column]->setColor('B');
    repaint();
}
