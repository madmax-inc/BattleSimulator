#include "CombatSituation.h"


CombatSituation::CombatSituation() : QObject(), TargetsContainer(), animationTimer(), endingTime(0), currentTime(0), state(STOPPED)
{
    QObject::connect(&animationTimer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
}

CombatSituation::CombatSituation(quint32 maxTime) : QObject(), TargetsContainer(), animationTimer(), endingTime(maxTime), currentTime(0), state(STOPPED)
{
    QObject::connect(&animationTimer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
}

bool CombatSituation::start() {
    if (state != RUNNING) {
        currentTime = 0;
        state = RUNNING;
        animationTimer.start(timerInterval);

        return true;
    } else {
        return false;
    }
}

bool CombatSituation::pause() {
    if (state == RUNNING) {
        state = PAUSED;
        animationTimer.stop();

        return true;
    } else {
        return false;
    }
}

bool CombatSituation::resume() {
    if (state == PAUSED) {
        state = RUNNING;
        animationTimer.start(timerInterval);

        return true;
    } else {
        return false;
    }
}

bool CombatSituation::stop() {
    if (state != STOPPED) {
        state = STOPPED;
        animationTimer.stop();

        return true;
    } else {
        return false;
    }
}

bool CombatSituation::rewind(quint32 time)
{
    if (time < endingTime) {
        currentTime = time;
        updateTargets();

        return true;
    } else {
        return false;
    }
}

AnimationState CombatSituation::getState() const {
    return state;
}

void CombatSituation::addTarget(const Target &target)
{
    targets.push_back(target);
}

Target& CombatSituation::getTarget(int index)
{
    return targets[index];
}

void CombatSituation::clearTargets()
{
    targets.clear();
}

void CombatSituation::updateTargets()
{
    for (QVector<Target>::iterator it = targets.begin(); it != targets.end(); ++it)
        it->setCurrentTime(currentTime);
}

TargetSnapshot CombatSituation::getTargetSnapshot(int index) const
{
    TargetSnapshot snap = targets.at(index).makeSnapshot(currentTime);
    return snap;
}

int CombatSituation::getTargetsCount() const
{
    return targets.size();
}

QDataStream& operator<<(QDataStream& out, const CombatSituation& b)
{
    out << b.endingTime << b.targets;

    return out;
}

QDataStream& operator>>(QDataStream& in, CombatSituation& b)
{
    in >> b.endingTime >> b.targets;

    return in;
}

void CombatSituation::onTimerFired()
{
    currentTime += timerInterval;

    if (currentTime >= endingTime)
        stop();

    updateTargets();
}
