#ifndef TARGETSNAPSHOT_H
#define TARGETSNAPSHOT_H

#include <QVector3D>

struct TargetSnapshot {
    QVector3D position;
    QVector3D velocity;
};

struct TargetEnrichedSnapshot {
    TargetSnapshot posInfo;

    int sourceNo;
    int inSourceIndex;
    int priority;
    unsigned long lastSeenTime;
};

#endif // TARGETSNAPSHOT_H
