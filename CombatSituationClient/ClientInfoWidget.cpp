#include "ClientInfoWidget.h"

ClientInfoWidget::ClientInfoWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* vbxLayout = new QVBoxLayout(this);
    text = new QTextEdit(this);
    vbxLayout->addWidget(text);
    this->setLayout(vbxLayout);
}

void ClientInfoWidget::appendInfoAboutTargets(const QVector<TargetSnapshot> &targets)
{
    if (!targets.empty())
        for (QVector<TargetSnapshot>::const_iterator it = targets.constBegin(); it!= targets.constEnd();++it)
        {
            text->append("Position: x = "+QString::number((*it).position.x())+";"+" y = "+
                        QString::number((*it).position.y())+";"+" z = "+QString::number((*it).position.z()));
        }
}

void ClientInfoWidget::appendString(const QString &string)
{
    text->append(string);
}

void ClientInfoWidget::addInfoAboutConnection()
{
    text->append("The client has been successfully connected to server");
}

void ClientInfoWidget::addErrorMessage(const QString &string)
{
     text->append(string);
}
