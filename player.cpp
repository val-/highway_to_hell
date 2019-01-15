#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/images/assets/cars/7.png"));

    QTimer * timerPosition = new QTimer(this);
    connect(timerPosition, SIGNAL(timeout()), this, SLOT(updatePosition()));
    timerPosition->start(40);

    QTimer * timerRate = new QTimer(this);
    connect(timerRate, SIGNAL(timeout()), this, SLOT(updateRate()));
    timerRate->start(200);

}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left) {
        rate -= 12;
    } else if (event->key() == Qt::Key_Right) {
        rate += 12;
    }
}

void Player::updateRate() {
    rate /= 3;
}


void Player::updatePosition() {
    setPos(x()+rate,y());
}
