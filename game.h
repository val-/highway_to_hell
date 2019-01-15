#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "road.h"
#include "traffic.h"

class Game: public QGraphicsView{
public:
    Game();

    QGraphicsScene * scene;
    Player * player;
    Road * road;
    Traffic * trafic;

    void stop();
    void start();

    bool isOver() {
        return over;
    }

private:
    bool over = false;

};

#endif // GAME_H
