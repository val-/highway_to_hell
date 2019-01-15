#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Car : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Car(QGraphicsItem * parent=nullptr, int row=0, int type=0, bool opposite=false);
public slots:
    void move();
private:
    int speed;
};

#endif // CAR_H
