#ifndef CLIENT_H
#define CLIENT_H

#include <QtWidgets>
#include "TCPAdapter.h"
#include "ClientInfoWidget.h"
#include "../CommonFiles/TargetsQueryProtocol.h"
#include "../CommonFiles/TargetSnapshot.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QString& ip, quint16 port, const TargetsQuery& protocol, QWidget *parent = 0);
    void showInfoWidget();
    void hideInfoWidget();
private slots:
    void getAllTargets();
    void initTargetsFromServerBySignal(QVector <TargetSnapshot> targets);
private:
    ClientInfoWidget infoWidget_;
    TCPAdapter*  adapter_;
    TargetsQuery protocol_;
    QVector <TargetSnapshot> targets_;
};

#endif // CLIENT_H
