#ifndef TARGETSQUERYPROTOCOL_H
#define TARGETSQUERYPROTOCOL_H

#include "TargetSnapshot.h"

struct TargetsQuery {
    TargetSnapshot owner;
    float angle;
    double distance;
};

#endif // TARGETSQUERYPROTOCOL_H
