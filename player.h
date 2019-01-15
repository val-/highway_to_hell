#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=nullptr);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void updateRate();
    void updatePosition();
private:
    int rate = 0;
};

#endif // PLAYER_H
