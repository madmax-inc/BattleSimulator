#ifndef CLIENTINFOWIDGET_H
#define CLIENTINFOWIDGET_H

#include <QtWidgets>
#include "../CommonFiles/TargetSnapshot.h"

class ClientInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClientInfoWidget(QWidget *parent = 0);
    void appendInfoAboutTargets(const QVector<TargetSnapshot>& targets);
    void appendString(const QString& string);
private:
    QTextEdit*   text;
private slots:
    void addInfoAboutConnection();
    void addErrorMessage(const QString& string);
};

#endif // CLIENTINFOWIDGET_H
