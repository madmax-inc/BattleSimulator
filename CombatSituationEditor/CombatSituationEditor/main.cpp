#include <QApplication>
#include <QFile>
#include <QDataStream>
#include "TargetsContainerPainterWidget.h"
#include "../../CommonFiles/CombatSituation.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QFile file("test.bin");

    file.open(QFile::ReadOnly);
    QDataStream stream(&file);

    CombatSituation sit;
    stream >> sit;

    file.close();


    TargetsContainerPainterWidget p(&sit);

    sit.start();

    p.show();

    return app.exec();
}
