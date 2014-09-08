#include <QApplication>

#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector3D op(0,0,0);
    QVector3D vel(0,0,0);
    TargetsQuery scannerProtocol;

    scannerProtocol.owner.position = op;
    scannerProtocol.owner.velocity = vel;
    scannerProtocol.distance = 100;
    scannerProtocol.angle = 360;

    Client client("localhost", 2323, scannerProtocol);
    client.showInfoWidget();
    return a.exec();
}
