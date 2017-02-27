#include "Controler.h"

#include <iostream>


Controller::Controller(const QObject *rootQmlObject) {
    subject.get_observable()
            .sample_with_time(std::chrono::milliseconds(200), rxcpp::serialize_event_loop())
            .subscribe([] (std::pair<qreal, qreal> pair) { std::cout << pair.first << " " << pair.second << std::endl; });

    connect(rootQmlObject, SIGNAL(ballMoved(qreal, qreal)), this, SLOT(onBallMoved(qreal,qreal)), Qt::QueuedConnection);
}

void Controller::onBallMoved(qreal x, qreal y) {
    subject.get_subscriber().on_next(std::make_pair(x, y));
}
