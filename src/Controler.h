#pragma once

#include <QObject>

#include <rx-includes.hpp>

class Controller : public QObject {
    Q_OBJECT

public:
    Controller(const QObject *rootQmlObject);

public slots:
    void onBallMoved(qreal x, qreal y);

private:
    rxcpp::subjects::subject<std::pair<qreal, qreal>> subject;
};
