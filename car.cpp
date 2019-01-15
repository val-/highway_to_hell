#include "car.h"
#include "game.h"
#include <QDebug>
#include <QString>

extern Game * game;

Car::Car(QGraphicsItem *parent, int row, int type, bool opposite): QObject(), QGraphicsPixmapItem(parent) {

    QString path = QString(":/images/assets/cars/") + QString::number(type) + QString(".png");

    //qDebug() << "Car image: " << path;

    setPixmap(QPixmap(path));
    if (opposite) setTransform(QTransform::fromScale(1, -1));

    speed = opposite ? 8 : 2;
    int offset = opposite ? 48 : 233;
    int positionX = offset + row * 60 - boundingRect().width()/2;

    setPos(positionX,-100);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);

}

void Car::move() {
    setPos(x(),y()+speed);
    if (pos().y() < -200 or pos().y() > 1000){
        game->scene->removeItem(this);
        delete this;
        qDebug() << "Car rip!!!";
    }
}
