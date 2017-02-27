#include <iostream>

#include <QApplication>
#include <QQuickView>

#include "Controler.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QQuickView view(QUrl("qrc:qml/main.qml"));

    Controller c((const QObject*)view.rootObject());

    view.show();
    return app.exec();
}
