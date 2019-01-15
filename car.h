#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Car : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Car(QGraphicsItem * parent=nullptr, int row=0, int type=0, bool opposite=false);
    void stop();
    void remove();
public slots:
    void move();
private:
    int speed;
    QTimer * timer;
};

#endif // CAR_H
