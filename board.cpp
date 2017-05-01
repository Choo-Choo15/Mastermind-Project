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
    row = i; //Row and column are "global" varaibles to allow the other methods to know what the most recentlty added space was
    column = j; //I dont really know how else to do it so maybe someone else has a good idea...
}

void board::on_submitButton_clicked()
{//it works!!!
    std::string g = "    ";
    for(int i = 0; i < 4; i++)
    {
        if(spaces[row][i]->getColor() == 0)
        {
            QMessageBox::about(this, tr("Cannot Submit"),
                        tr("Cannot submit until all values have been filled in for this row."));
            break;
        }
        else
        {
            g[i] = spaces[row][i]->getColor();
        }
    }
    if(g.find('0') != std::string::npos)
    {
        g = "    ";
    }
    else
    {
        guess.setGuess(g);
        guess.checkPattern(); //not positive this method works
        setChecked(row);
    }
}

void board::setChecked(int inRow)
{
    for(int i = 0; i < 4; i++)
    {
        spaces[inRow][i]->setChecked();
    }
}

void board::on_clearButton_clicked()//this method will need something to stop users from undo ing an already checked move!
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
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('N');
        repaint();
    }
}

void board::on_redButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('R');
        repaint();
    }
}

void board::on_yellowButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('Y');
        repaint();
    }
}

void board::on_greenButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('G');
        repaint();
    }
}

void board::on_purpleButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('P'); //shows magenta... not sure how to show purple
        repaint();
    }
}

void board::on_orangeButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('O'); //shows darkRed... not sure how to show orange
        repaint();
    }
}

void board::on_whiteButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('W');
        repaint();
    }
}

void board::on_blackButton_clicked()
{
    if(!spaces[row][3]->getChecked() && spaces[row][3]->getColor() != 0)
    {
        QMessageBox::about(this,tr("Invalid Move"), tr("Cannot add another value until"
                                                       " you have submitted this full row."));
    }
    else
    {
        getCurrentSpace();
        spaces[row][column]->setColor('B');
        repaint();
    }
}
