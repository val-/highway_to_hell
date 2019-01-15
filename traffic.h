#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <QObject>
#include "car.h"

class Traffic: public QObject {
    Q_OBJECT
public:
    explicit Traffic(QObject *parent = nullptr);

public slots:
    void spawn();
};

#endif // TRAFFIC_H
