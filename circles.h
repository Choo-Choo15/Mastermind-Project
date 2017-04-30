#ifndef CIRCLES_H
#define CIRCLES_H

#include <QPainter>
#include <QWidget>

class Circles : public QWidget
{
    Q_OBJECT

private:
    int row, col;
    bool checked;
    char color;
    QPainter painter;

protected:
    void paintEvent(QPaintEvent *);


public:
    explicit Circles(QWidget *parent = 0);
    char getColor();
    void setColor(char Color);
    //~Circles();

signals:

public slots:
};

#endif // CIRCLES_H
