#include "TargetsQueryProtocol.h"

// Serialization TargetsQuery

QDataStream& operator << (QDataStream& out, const TargetsQuery& target)
{
    out << target.owner;
    out << target.angle;
    out << target.distance;
    return out;
}

QDataStream& operator << (QDataStream& in, TargetsQuery& target)
{
    in >> target.owner;
    in >> target.angle;
    in >> target.distance;
    return in;
}
