#include "Client.h"
#include <QVector3D>

Client::Client(const QString &ip, quint16 port, const TargetsQuery &protocol, QWidget *parent) :
    QObject(parent), protocol_(protocol)
{
    adapter_ = new TCPAdapter(ip, port);

    QObject::connect(adapter_, SIGNAL(connected()), &infoWidget_, SLOT(addInfoAboutConnection()));
    QObject::connect(adapter_, SIGNAL(connectionFailed(QString)), &infoWidget_, SLOT(addErrorMessage(QString)));
    QObject::connect(adapter_, SIGNAL(targetsReceived(QVector<TargetSnapshot>)), this,
                              SLOT(initTargetsFromServerBySignal(QVector<TargetSnapshot>)));

    getAllTargets();
}

void Client::getAllTargets()
{
    adapter_->sentQueryAndReadTargets(protocol_);
}

void Client::initTargetsFromServerBySignal(QVector<TargetSnapshot> targets)
{
    targets_ = targets;
    infoWidget_.appendString("Targets has been received\n");
    infoWidget_.appendInfoAboutTargets(targets_);
}

void Client::showInfoWidget()
{
    infoWidget_.show();
}

void Client::hideInfoWidget()
{
    infoWidget_.hide();
}
