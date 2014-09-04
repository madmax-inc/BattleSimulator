#ifndef TARGETSQUERYPROTOCOL_H
#define TARGETSQUERYPROTOCOL_H

#include "TargetSnapshot.h"
#include <QDataStream>

struct TargetsQuery {
    TargetSnapshot owner;
    float angle;
    double distance;
};

QDataStream& operator << (QDataStream& out, const TargetsQuery& target);
QDataStream& operator >> (QDataStream& in, TargetsQuery& target);

#endif // TARGETSQUERYPROTOCOL_H
