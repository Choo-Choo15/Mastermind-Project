#ifndef CIRCLES_H
#define CIRCLES_H
#include <QPainter>
#include <QWidget>

class Circles : public QWidget
{
private:
    Q_OBJECT
    int row, col;
    bool empty;
    char color;
    QPainter painter;

protected:
    void paintEvent(QPaintEvent *);

public:
   explicit Circles(QWidget *pParent = 0);
   char getColor();
   void setColor(char Color);
   //~Circles();

};

#endif // SPACES_H
