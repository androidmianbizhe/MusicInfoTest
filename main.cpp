#include <QApplication>
#include <QQmlApplicationEngine>

#include "MainFrame.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    QObject *obj = engine.rootObjects()[0];

    MainFrameWin mainframe(obj);

    return app.exec();
}
