#include "car.h"
#include "game.h"
#include "player.h"
#include <QDebug>
#include <QString>
#include <QList>

extern Game * game;

Car::Car(QGraphicsItem *parent, int row, int type, bool opposite): QObject(), QGraphicsPixmapItem(parent) {

    QString path = QString(":/images/assets/cars/") + QString::number(type) + QString(".png");

    setPixmap(QPixmap(path));
    if (opposite) setTransform(QTransform::fromScale(1, -1));

    speed = opposite ? 8 : 2;
    int offset = opposite ? 48 : 233;
    int positionX = offset + row * 60 - boundingRect().width()/2;

    setPos(positionX,-100);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);

}

void Car::move() {


    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->stop();
            return;
        }
    }

    setPos(x(),y()+speed);

    if (pos().y() < -200 or pos().y() > 1000){
        remove();
    }
}

void Car::stop() {
    timer->stop();
}

void Car::remove() {
    game->scene->removeItem(this);
}
