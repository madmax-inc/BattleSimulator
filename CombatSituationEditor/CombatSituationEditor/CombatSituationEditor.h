#ifndef COMBATSITUATIONEDITOR_H
#define COMBATSITUATIONEDITOR_H

#include <QMainWindow>
#include "../../CommonFiles/CombatSituation.h"

class CombatSituationEditor : public QMainWindow
{
    Q_OBJECT
    private:
        CombatSituation* currentSituation;

    public:
        CombatSituationEditor(QWidget *parent = 0);

    private:
        void createMenus();

    private slots:
        void onNewCombatSituation();
        void onOpenCombatSituation();
        void onSaveCombatSituation();
        void onSaveAsCombatSituation();
        void onExit();

        void onAddNewTarget();
        void onClearTargets();

        void onAbout();
        void onAboutAuthors();
        void onAboutQt();
    signals:

    public slots:

};

#endif // COMBATSITUATIONEDITOR_H
