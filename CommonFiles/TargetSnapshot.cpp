#include "TargetSnapshot.h"

// Serialization  TargetSnapshot
QDataStream& operator << (QDataStream& out, const TargetSnapshot& target)
{
    out << target.position;
    out << target.velocity;
    return out;
}

QDataStream& operator >> (QDataStream& in, TargetSnapshot& target)
{
    in >> target.position;
    in >> target.velocity;
    return in;
}

// Serialization TargetEnrichedSnapshot
QDataStream& operator << (QDataStream& out, const TargetEnrichedSnapshot& target)
{
    out << target.posInfo;
    out << target.sourceNo;
    out << target.inSourceIndex;
    out << target.priority;
    out << target.lastSeenTime;
    return out;
}

QDataStream& operator >> (QDataStream& in, TargetEnrichedSnapshot& target)
{
    in >> target.posInfo;
    in >> target.sourceNo;
    in >> target.inSourceIndex;
    in >> target.priority;
    in >> target.lastSeenTime;
    return in;
}
