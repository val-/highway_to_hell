#include "traffic.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;

Traffic::Traffic(QObject *parent) : QObject(parent) {

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(800);

}

void Traffic::spawn() {
    int row = (rand() % 3);
    int type = (rand() % 10);
    bool opposite = (rand() % 2);
    Car * car = new Car(nullptr, row, type, opposite);
    game->scene->addItem(car);
}
