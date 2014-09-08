#ifndef TCPADAPTER_H
#define TCPADAPTER_H

#include <QObject>
#include <QtNetwork>

#include "../CommonFiles/TargetSnapshot.h"
#include "../CommonFiles/TargetsQueryProtocol.h"

class TCPAdapter : public QObject
{
    Q_OBJECT
public:
    explicit TCPAdapter(const QString& ip, quint16 port, QObject* parent = 0);
    QString getHostIP()   const;
    quint16 getHostPort() const;
public slots:
    void sentQueryAndReadTargets(const TargetsQuery& protocolFromClient);
private slots:
    void slotError(QAbstractSocket::SocketError err);
    void readTargets();
signals:
    void connectionFailed(const QString& stringError);
    void connected();
    void targetsReceived(QVector <TargetSnapshot>);
private:
    QTcpSocket* serverSocket_;
    QString     hostIP_;
    quint16     hostPort_;
    quint16     nextBlockSize_;
};

#endif // TCPADAPTER_H
