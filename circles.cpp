#include "circles.h"

#include <QPainter>
#include <QWidget>
#include <QGraphicsObject>

Circles::Circles(QWidget *pParent) : QWidget(pParent)
{
    color = 0;
    checked = false;
}

char Circles::getColor()
{
    return color;
}

void Circles::setColor(char Color)
{
    color = Color;
}

void Circles::setChecked()
{
    checked = true;
}

bool Circles::getChecked()
{
    return checked;
}

/*Circles::~Circles()
{
    delete Circles;
}*/ //would like to add but throws erros

void Circles::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    switch (color) {
    case 'R':
        painter.setBrush(QBrush(QColor("red")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'N':
        painter.setBrush(QBrush(QColor("darkBlue")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'P':
        painter.setBrush(QBrush(QColor(170,0,255,255)));//cant figure out how to show purple like button!
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'G':
        painter.setBrush(QBrush(QColor("green")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'Y':
        painter.setBrush(QBrush(QColor("yellow")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'O':
        painter.setBrush(QBrush(QColor(255,170,0,255)));//cant figure out how to show orange like button!
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'W':
        painter.setBrush(QBrush(QColor("white")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    case 'B':
        painter.setBrush(QBrush(QColor("black")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    default:
        painter.setBrush(QBrush(QColor("lightGray")));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(QPoint(width()/2, height()/2),25,25);
        break;
    }
}
