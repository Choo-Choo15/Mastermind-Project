#include "circlesfeedback.h"

#include <QPainter>
#include <QWidget>

CirclesFeedback::CirclesFeedback(QWidget *parent) : QWidget(parent)
{

}

void CirclesFeedback::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor("lightGray")));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(width()/2, height()/2),10,10);
}

/*
void HoleReview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(black)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(0, 0, 20, 20);
    }
    else if(white)
    {
        painter->setBrush(Qt::white);
        painter->drawEllipse(0, 0, 20, 20);
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->drawEllipse(0, 0, 20, 20);
    }
}

void CirclesFeedback::blackPaint()
{
    black = true;
}

void CirclesFeedback::whitePaint()
{
    white = true;
}*/
