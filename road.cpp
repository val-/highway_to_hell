#include "road.h"
#include "game.h"

extern Game * game;

Road::Road(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/images/assets/bg.png"));
    updatePosition();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition()));
    start();

}

void Road::updatePosition() {
    if (position < -5) position += 10;
    else position = -800;
    setPos(x(),position);
}

void Road::stop() {
    timer->stop();
}

void Road::start() {
    timer->start(40);
}
