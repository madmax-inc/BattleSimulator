#include "Chronometer.h"

Chronometer::Chronometer(quint32 accuracy) : QObject(), timer(), speed(1.0), endingTime(0), currentTime(0), timerInterval(accuracy), state(STOPPED)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
}

bool Chronometer::start() {
    if (state != RUNNING) {
        currentTime = 0;
        state = RUNNING;
        timer.start(timerInterval);

        return true;
    } else {
        return false;
    }
}

bool Chronometer::pause() {
    if (state == RUNNING) {
        state = PAUSED;
        timer.stop();

        return true;
    } else {
        return false;
    }
}

bool Chronometer::resume() {
    if (state == PAUSED) {
        state = RUNNING;
        timer.start(timerInterval);

        return true;
    } else {
        return false;
    }
}

bool Chronometer::stop() {
    if (state != STOPPED) {
        state = STOPPED;
        timer.stop();

        return true;
    } else {
        return false;
    }
}

bool Chronometer::rewind(quint32 time)
{
    if (time < endingTime) {
        currentTime = time;

        return true;
    } else {
        return false;
    }
}

void Chronometer::setSpeed(qreal spd) {
    speed = spd;
}

Chronometer::ChronometerState Chronometer::getState() const {
    return state;
}

quint32 Chronometer::getCurrentTime() const
{
    return currentTime;
}

quint32 Chronometer::getEndingTime() const
{
    return endingTime;
}

void Chronometer::setEndingTime(quint32 time)
{
    endingTime = time;
}


//Serialization
QDataStream& operator<<(QDataStream& out, const Chronometer& b)
{
    out << b.endingTime;

    return out;
}

QDataStream& operator>>(QDataStream& in, Chronometer& b)
{
    in >> b.endingTime;

    return in;
}

void Chronometer::onTimerFired()
{
    currentTime += timerInterval * speed;

    if (currentTime >= endingTime) {
        stop();
        emit timerOverflow();
    }
}
