#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QFile>
#include <QVector>

#include "../CommonFiles/TargetSnapshot.h"
#include "../CommonFiles/TargetsQueryProtocol.h"
#include "../CommonFiles/CombatSituation.h"

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(int port, const QString& fileNameWithCombatSituation, QObject* parent = 0);

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
private:
    QTcpServer* tcpServer_;
    quint16     port_;
    quint16     nextBlockSize_;
    QFile       file_;
    QVector <TargetSnapshot> getTargetsFromFile(const TargetsQuery& query);
    void                     sendToClient(QTcpSocket* socket, const QVector <TargetSnapshot>& targets);
};

#endif // TCPSERVER_H
