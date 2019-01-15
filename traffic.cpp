#include "traffic.h"
#include "game.h"
#include <QGraphicsScene>

extern Game * game;

Traffic::Traffic(QObject *parent) : QObject(parent) {

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    start();

}

void Traffic::spawn() {
    if (cars.size() > 1024) clear(); // TODO: optimize
    int row = (rand() % 3);
    int type = (rand() % 10);
    bool opposite = (rand() % 2);
    Car * car = new Car(nullptr, row, type, opposite);
    cars.push_back(car);
    game->scene->addItem(car);
}

void Traffic::stop() {
    timer->stop();
    for (auto it = begin (cars); it != end (cars); ++it) {
        (*it)->stop();
    }
}

void Traffic::start() {
    timer->start(800);
}

void Traffic::clear() {
    for (auto it = begin (cars); it != end (cars); ++it) {
        (*it)->remove();
    }
    cars.clear();
}

