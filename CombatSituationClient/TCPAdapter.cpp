#include "TCPAdapter.h"

TCPAdapter::TCPAdapter(const QString &ip, quint16 port, QObject *parent) :
    QObject(parent), hostIP_(ip), hostPort_(port)
{
    serverSocket_ = new QTcpSocket(this);
    serverSocket_->connectToHost(hostIP_, hostPort_);
    connect(serverSocket_, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(serverSocket_, SIGNAL(readyRead()), SLOT(readTargets()));
    connect(serverSocket_, SIGNAL(error(QAbstractSocket::SocketError)),
            SLOT(slotError(QAbstractSocket::SocketError)));
    nextBlockSize_ = 0;
}

QString TCPAdapter::getHostIP() const
{
    return hostIP_;
}

quint16 TCPAdapter::getHostPort() const
{
    return hostPort_;
}

void TCPAdapter::sentQueryAndReadTargets(const TargetsQuery &protocolFromClient)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << protocolFromClient;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    serverSocket_->write(arrBlock);
}

void TCPAdapter::readTargets()
{
    QDataStream in(serverSocket_);
    in.setVersion(QDataStream::Qt_4_7);
    QVector <TargetSnapshot> targetsFromServer;
    while(true)
    {
        if (!nextBlockSize_)
        {
            if (serverSocket_->bytesAvailable() < (int)sizeof(quint16))
                break;
            in >> nextBlockSize_;
        }
        if (serverSocket_->bytesAvailable() < nextBlockSize_)
            break;
        in >> targetsFromServer;
        nextBlockSize_ = 0;
    }
    emit targetsReceived(targetsFromServer);
}

void TCPAdapter::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString(serverSocket_->errorString())
                    );
    emit connectionFailed(strError);
}
