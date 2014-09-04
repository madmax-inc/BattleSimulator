#include "../../CommonFiles/MovementCurve.h"
#include "../../CommonFiles/LagrangeInterpolation.h"
#include "../../CommonFiles/Target.h"
#include "../../CommonFiles/TargetSnapshot.h"
#include "../../CommonFiles/CombatSituation.h"
#include <iostream>
#include <QCoreApplication>

using namespace std;


int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);

    MovementCurve<LagrangeInterpolationFunction> curve;

    curve.addPoint(0, 1, 2, 3);
    curve.addPoint(10000, 21, -2, 53);
    curve.addPoint(20000, 12, 0, 11);
    curve.addPoint(30000, 6, 8, 57);

    Target<LagrangeInterpolationFunction> t1(QVector3D(1, 2, 3), curve);

    CombatSituation sit(30000, 25);

    sit.addTarget(t1);

    sit.start();

    return app.exec();
}
