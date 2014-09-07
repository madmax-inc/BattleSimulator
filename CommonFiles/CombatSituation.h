#ifndef COMBATSITUATION_H
#define COMBATSITUATION_H

#include "TargetsContainer.h"
#include <QObject>
#include <QVector>
#include "Target.h"
#include <QDataStream>
#include <QTimer>

enum AnimationState {
    STOPPED,
    PAUSED,
    RUNNING
};

class CombatSituation : public QObject, public TargetsContainer {
    Q_OBJECT
    private:
        QVector<Target> targets;
        QTimer animationTimer;
        quint32 endingTime;
        quint32 currentTime;
        const int timerInterval = 25;
        AnimationState state;

    public:
        CombatSituation();
        CombatSituation(quint32 maxTime);
        ~CombatSituation() {

        }

        bool start();
        bool pause();
        bool resume();
        bool stop();
        bool rewind(quint32 time);

        AnimationState getState() const;

        void addTarget(const Target& target);
        Target& getTarget(int index);
        void clearTargets();

    private:
        void updateTargets();

    public:
        TargetSnapshot getTargetSnapshot(int index) const;
        int getTargetsCount() const;

        //Serialization override
        friend QDataStream& operator<<(QDataStream& out, const CombatSituation& b);
        friend QDataStream& operator>>(QDataStream& in, CombatSituation& b);

    private slots:
        void onTimerFired();
};

#endif // COMBATSITUATION_H
