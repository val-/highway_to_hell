#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Road : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Road(QGraphicsItem * parent=nullptr);
    void stop();
    void start();
public slots:
    void updatePosition();
private:
    int position = -800;
    QTimer * timer;
};

#endif // ROAD_H
