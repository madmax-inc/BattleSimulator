#ifndef TARGETSNAPSHOT_H
#define TARGETSNAPSHOT_H

#include <QVector3D>
#include <QDataStream>

struct TargetSnapshot {
    QVector3D position;
    QVector3D velocity;
};

QDataStream& operator << (QDataStream& out, const TargetSnapshot& target);
QDataStream& operator >> (QDataStream& in, TargetSnapshot& target);

struct TargetEnrichedSnapshot {
    TargetSnapshot posInfo;

    int sourceNo;
    int inSourceIndex;
    int priority;
    unsigned long lastSeenTime;
};

QDataStream& operator << (QDataStream& out, const TargetEnrichedSnapshot& target);
QDataStream& operator >> (QDataStream& in, TargetEnrichedSnapshot& target);

#endif // TARGETSNAPSHOT_H
