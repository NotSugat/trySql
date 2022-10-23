#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "database.h"
#include "listmodel.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    DataBase database;
       database.connectToDataBase();

       ListModel *model = new ListModel();

       engine.rootContext()->setContextProperty("myModel", model);
       engine.rootContext()->setContextProperty("database", &database);


    const QUrl url(u"qrc:/trySql/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
