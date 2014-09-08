#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <QTimer>
#include <QObject>
#include <QDataStream>

class Chronometer : public QObject {
    Q_OBJECT
    private:
        enum ChronometerState {
            STOPPED,
            PAUSED,
            RUNNING
        };

        QTimer timer;
        qreal speed;
        quint32 endingTime;
        quint32 currentTime;
        quint32 timerInterval;
        ChronometerState state;

    public:
        Chronometer(quint32 accuracy = 25);

        bool start();
        bool pause();
        bool resume();
        bool stop();
        bool rewind(quint32 time);
        void setSpeed(qreal spd);

        ChronometerState getState() const;
        quint32 getCurrentTime() const;
        quint32 getEndingTime() const;

        void setEndingTime(quint32 time);

        //Serialization
        friend QDataStream& operator<<(QDataStream& out, const Chronometer& b);
        friend QDataStream& operator>>(QDataStream& in, Chronometer& b);

    signals:
        void timerOverflow();

    private slots:
        void onTimerFired();
};


#endif // CHRONOMETER_H
