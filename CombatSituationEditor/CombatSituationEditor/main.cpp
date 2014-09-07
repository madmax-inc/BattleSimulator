#include <QApplication>
#include <QFile>
#include <QDataStream>
#include "CombatSituationEditorWidget.h"
#include "../../CommonFiles/CombatSituation.h"
//#include "../../CommonFiles/Target.h"
//#include "../../CommonFiles/MovementCurve.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QFile file("../../CommonFiles/situation30_lined.sit");

    file.open(QFile::ReadOnly);
    QDataStream stream(&file);

    CombatSituation sit;
    stream >> sit;

    file.close();


    CombatSituationEditorWidget p(&sit);
    p.containerChanged();

    p.show();

    return app.exec();
}

/*int main() {
    CombatSituation sit(30000);

    MovementCurve<LagrangeInterpolationFunction> curve1;
    MovementCurve<LagrangeInterpolationFunction> curve2;
    MovementCurve<LagrangeInterpolationFunction> curve3;
    MovementCurve<LagrangeInterpolationFunction> curve4;

    curve1.addPoint(0, -50, -10, 0);
    curve1.addPoint(5000, -20, -5, 5);
    curve1.addPoint(20000, 30, 15, 10);
    curve1.addPoint(30000, 20, 0, 30);

    curve2.addPoint(0, 70, -10, 30);
    curve2.addPoint(15000, -5, 30, 15);
    curve2.addPoint(20000, 10, 15, 10);
    curve2.addPoint(30000, 20, 10, 5);

    curve3.addPoint(0, 10, 10, 5);
    curve3.addPoint(10000, 5, 60, 7);
    curve3.addPoint(15000, 0, 35, 10);
    curve3.addPoint(20000, -10, 50, 25);
    curve3.addPoint(30000, -30, 20, 10);

    curve4.addPoint(0, 0, 70, 2);
    curve4.addPoint(20000, 15, 15, 10);
    curve4.addPoint(30000, -5, 7, 5);


    Target<LagrangeInterpolationFunction> tar1(curve1);
    Target<LagrangeInterpolationFunction> tar2(curve2);
    Target<LagrangeInterpolationFunction> tar3(curve3);
    Target<LagrangeInterpolationFunction> tar4(curve4);

    sit.addTarget(tar1);
    sit.addTarget(tar2);
    sit.addTarget(tar3);
    sit.addTarget(tar4);

    QFile file("situation30.sit");

    file.open(QFile::WriteOnly);

    QDataStream stream(&file);

    stream << sit;

    file.close();

    return 0;
}*/

/*
int main() {
    CombatSituation sit(30000);

    MovementCurve<> curve1;
    MovementCurve<> curve2;
    MovementCurve<> curve3;
    MovementCurve<> curve4;

    curve1.addPoint(0, -50, -10, 0);
    curve1.addPoint(30000, 20, 0, 30);

    curve2.addPoint(0, 70, -10, 30);
    curve2.addPoint(30000, 20, 10, 5);

    curve3.addPoint(0, 10, 10, 5);
    curve3.addPoint(30000, -30, 20, 10);

    curve4.addPoint(0, 0, 70, 2);
    curve4.addPoint(30000, -5, 7, 5);


    Target tar1(curve1);
    Target tar2(curve2);
    Target tar3(curve3);
    Target tar4(curve4);

    sit.addTarget(tar1);
    sit.addTarget(tar2);
    sit.addTarget(tar3);
    sit.addTarget(tar4);

    QFile file("situation30_lined.sit");

    file.open(QFile::WriteOnly);

    QDataStream stream(&file);

    stream << sit;

    file.close();

    return 0;
}*/
