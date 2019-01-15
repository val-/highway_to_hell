#include "road.h"

Road::Road(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/images/assets/bg.png"));
    updatePosition();

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePosition()));
    timer->start(40);

}

void Road::updatePosition() {
    if (position < -5) position += 10;
    else position = -800;
    setPos(x(),position);
}
