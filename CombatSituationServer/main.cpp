#include <QCoreApplication>
#include "TCPServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TCPServer server(2323, "C:/Users/andre/Documents/GitHub/BattleSimulator/CommonFiles/situation30.sit");
    return a.exec();
}
