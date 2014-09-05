#include <QApplication>
#include <QFile>
#include <QDataStream>
#include "../../CommonFiles/CombatSituation.h"
#include "../../CommonFiles/Target.h"
#include "../../CommonFiles/MovementCurve.h"
#include "../../CommonFiles/LagrangeInterpolation.h"

int main(int argc, char** argv) {
    //QApplication app(argc, argv);

    MovementCurve<LagrangeInterpolationFunction> curve;

    curve.addPoint(0, 1, 2, 3);
    curve.addPoint(10000, 10, -2, 15);
    curve.addPoint(40000, 34, 90, 0);
    curve.addPoint(60000, 15, -11, 72);

    Target<LagrangeInterpolationFunction> tar1(curve);

    CombatSituation sit(60000);

    sit.addTarget(tar1);

    QFile file("TestSituation.sit");

    file.open(QFile::WriteOnly);
    QDataStream stream(&file);

    stream << sit;

    file.close();


    return 0;
}
