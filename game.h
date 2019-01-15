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
    Game(QWidget * parent=nullptr);

    QGraphicsScene * scene;
    Player * player;
    Road * road;
    Traffic * trafic;

};

#endif // GAME_H
