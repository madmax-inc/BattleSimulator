#include "CombatSituation.h"


CombatSituation::CombatSituation(double maxTime, double interval) : QObject(), TargetsContainer(), animationTimer(), endingTime(maxTime), timerInterval(interval), state(STOPPED)
{
    QObject::connect(&animationTimer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
}

bool CombatSituation::start() {
    if (state != RUNNING) {
        //TODO Подсчет времени начала и окончания анимации
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

AnimationState CombatSituation::getState() const {
    return state;
}

void CombatSituation::addTarget(const Target<LagrangeInterpolationFunction> &target)
{
    targets.push_back(target);
}

void CombatSituation::clearTargets()
{
    targets.clear();
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
    out << b.targets;

    return out;
}

QDataStream& operator>>(QDataStream& in, CombatSituation& b)
{
    in >> b.targets;

    return in;
}

void CombatSituation::onTimerFired()
{
    currentTime += timerInterval;

    if (currentTime >= endingTime)
        stop();
}
