#ifndef TARGETSCONTAINER_H
#define TARGETSCONTAINER_H

#include "TargetSnapshot.h"

class TargetsContainer {
    public:
        virtual TargetSnapshot getTargetSnapshot(int index) const = 0;
        virtual int getTargetsCount() const = 0;
};


#endif // TARGETSCONTAINER_H
