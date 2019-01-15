#include "game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,400,800);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,800);

    road = new Road();
    scene->addItem(road);

    player = new Player();
    player->setPos(100,550);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    trafic = new Traffic();

    show();
}
