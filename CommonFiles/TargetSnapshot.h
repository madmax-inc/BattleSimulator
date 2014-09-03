#ifndef TARGETSNAPSHOT_H
#define TARGETSNAPSHOT_H

#include "Geometry.h"

struct TargetSnapshot {
    Vector3D<double> position;
    Vector3D<double> velocity;
};

struct TargetEnrichedSnapshot {
    TargetSnapshot posInfo;

    int sourceNo;
    int inSourceIndex;
    int priority;
    unsigned long lastSeenTime;
};

#endif // TARGETSNAPSHOT_H
