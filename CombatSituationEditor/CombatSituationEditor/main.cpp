#include "../../CommonFiles/MovementCurve.h"
#include "../../CommonFiles/LagrangeInterpolation.h"
#include "../../CommonFiles/Geometry.h"
#include "../../CommonFiles/TargetSnapshot.h"
#include <iostream>

using namespace std;

int main() {
    MovementCurve<LagrangeInterpolationFunction> curve;

    curve.addPoint(0, 1, 2, 3);
    curve.addPoint(1, 21, -2, 53);
    curve.addPoint(2, 12, 0, 11);
    curve.addPoint(3, 6, 8, 57);

    TargetSnapshot a = curve(2);
    TargetSnapshot b = curve(2.5);

    cout << a.position.getX() << " " << a.position.getY() << " " << a.position.getZ() << endl;
    cout << b.position.getX() << " " << b.position.getY() << " " << b.position.getZ() << endl;

    return 0;
}
