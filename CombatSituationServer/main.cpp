#include <QCoreApplication>
#include "TCPServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TCPServer server(2323, "battle_situation.txt");
    return a.exec();
}
