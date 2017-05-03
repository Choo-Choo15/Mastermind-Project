#ifndef CIRCLESFEEDBACK_H
#define CIRCLESFEEDBACK_H

#include <QWidget>

class CirclesFeedback : public QWidget
{
    Q_OBJECT
public:
    explicit CirclesFeedback(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    char getColor();
    void setColor(char Color);

private:
    char color;

signals:

public slots:
};

#endif // CIRCLESFEEDBACK_H
