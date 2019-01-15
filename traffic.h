#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <QObject>
#include <vector>
#include <QTimer>
#include "car.h"

class Traffic: public QObject {
    Q_OBJECT
public:
    explicit Traffic(QObject *parent = nullptr);
    void stop();
    void start();
    void clear();

public slots:
    void spawn();

private:
    std::vector<Car *> cars;
    QTimer * timer;
};

#endif // TRAFFIC_H
