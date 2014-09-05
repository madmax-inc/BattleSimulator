#include "TCPServer.h"

#include <QDataStream>
#include <QString>
#include <iostream>

using namespace std;

TCPServer::TCPServer(int port, const QString& fileNameWithCombatSituation, QObject* parent):
    QObject(parent), port_(port)
{
    // Setting filename of file with combat situation.
    file_.setFileName(fileNameWithCombatSituation);

    tcpServer_ = new QTcpServer(this);
    if (!tcpServer_->listen(QHostAddress::Any, port_))
    {
        cout << "Server Error", "Unable to start the server:" + tcpServer_->errorString();
        tcpServer_->close();
        return;
    }
    connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // Finding the first IPv4 adress, which is not a localhost.
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // If we did not find use localhost.
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    cout << "The server is running on\nIP: " << ipAddress.toStdString() <<
            endl << "Port: " << port_ << endl;
}

void TCPServer::slotNewConnection()
{
    QTcpSocket* pClientSocket = tcpServer_->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()),pClientSocket, SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
    cout << "The client has been successfully connected." << endl;
}

void TCPServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_7);
    while(true)
    {
        if (!nextBlockSize_)
        {
            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16))
                break;
            in >> nextBlockSize_;
        }
        if (pClientSocket->bytesAvailable() < nextBlockSize_)
            break;

        // Reading the protocol from client
        TargetsQuery protocolFromClient;
        in >> protocolFromClient;

        // Analyse the protocol in order to prepare data for sending.
        QVector<TargetSnapshot> targets = getTargetsFromFile(protocolFromClient);

        // Sending the targets to client.
        nextBlockSize_ = 0;
        sendToClient(pClientSocket, targets);
    }
}

void TCPServer::sendToClient(QTcpSocket* socket, const QVector <TargetSnapshot>& targets)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    out << quint16(0) << targets;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    socket->write(arrBlock);
}

QVector<TargetSnapshot> TCPServer::getTargetsFromFile(const TargetsQuery &query)
{
    // Reading the combat situation from file.
    CombatSituation situation;
    if (file_.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&file_);
        stream.setVersion(QDataStream::Qt_4_7);
        stream >> situation;
        if (stream.status() != QDataStream::Ok)
            cout << "Read error!" << endl;
        file_.close();
     }
   // Forming the vector by analysing the query.
   QVector<TargetSnapshot> vectorToSend;
   for (int index = 0; index < situation.getTargetsCount(); index++)
   {
       TargetSnapshot targetSnapshot = situation.getTargetSnapshot(index);
       // Checking if target is in the area.
       QVector3D clientDirection = query.owner.velocity;
       QVector3D targetDirection = targetSnapshot.position - query.owner.position;
       float distance = targetDirection.length();

       clientDirection.normalize();
       targetDirection.normalize();
       float cosAngle = QVector3D::dotProduct(clientDirection, targetDirection);
       float angle = acos(cosAngle) * 180.0 / 3.1415926f;

       if (angle < query.angle && distance < query.distance)
            vectorToSend.push_back(targetSnapshot);
   }
   return vectorToSend;
}
